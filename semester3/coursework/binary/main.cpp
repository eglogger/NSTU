#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <regex>
#include <vector>

struct Record {

    bool isDeleted = false;  // Mark if the record is deleted
    std::string category;    // "Buy" or "Sell"
    std::string rubric;      // "Transport", "Real Estate", etc.
    std::string text;        // Ad text
    std::string date;        // Date in YYYY-MM-DD format
    std::string phone;       // Contact phone number
};

std::string normalizeDate(const std::string& inputDate) {

    std::regex datePattern(R"((\d{4})-(\d{1,2})-(\d{1,2}))");
    std::smatch match;

    if (std::regex_match(inputDate, match, datePattern)) {
        int year = std::stoi(match[1]);
        int month = std::stoi(match[2]);
        int day = std::stoi(match[3]);

        if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            std::ostringstream formattedDate;
            formattedDate << std::setw(4) << std::setfill('0') << year << "-"
                          << std::setw(2) << std::setfill('0') << month << "-"
                          << std::setw(2) << std::setfill('0') << day;
            return formattedDate.str();
        }
    }

    throw std::invalid_argument("Invalid date format. Expected YYYY-MM-DD.");
}

void checkFileSize(const std::string& filename) {

    namespace fs = std::filesystem;

    if (fs::exists(filename)) {
        std::cout << "File size: " << fs::file_size(filename) << " bytes\n";
    }

    else {
        std::cout << "File does not exist.\n";
    }
}

struct Node {

    Record data;
    Node* next;

    Node(const Record& record) : data(record), next(nullptr) {}
};

class BulletinBoard {

    Node* head;
    bool isCompressed;

public:

    BulletinBoard() : head(nullptr), isCompressed(false) {}

    ~BulletinBoard() {
        clear();
    }

    void addRecord(const Record& record) {

        Node* newNode = new Node(record);

        if (!head) {
            head = newNode;
        }

        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        isCompressed = false;
    }

    size_t calculateRecordSize(const Record& record) {

        return sizeof(record.isDeleted) +
               record.category.size() +
               record.rubric.size() +
               record.text.size() +
               record.date.size() +
               record.phone.size();
    }

    std::string removeTrailingFillers(const std::string& str) {

        size_t end = str.find_last_not_of('\0');

        if (end == std::string::npos) {
            return "";
        }

        return str.substr(0, end + 1);
    }

    void modifyRecord(size_t userIndex) {

        if (!head) {
            std::cout << "No records to modify." << std::endl;
            return;
        }

        Node* current = head;
        size_t currentIndex = 1;

        while (current) {
            if (!current->data.isDeleted) {
                if (currentIndex == userIndex) {

                    std::cout << "Modifying Record #" << userIndex << ":\n";
                    displayRecord(current->data, userIndex);

                    size_t oldSize = calculateRecordSize(current->data);

                    std::cout << "Enter new category (or press Enter to keep unchanged): ";
                    std::string input;
                    std::getline(std::cin, input);
                    if (!input.empty()) current->data.category = input;

                    std::cout << "Enter new rubric (or press Enter to keep unchanged): ";
                    std::getline(std::cin, input);
                    if (!input.empty()) current->data.rubric = input;

                    std::cout << "Enter new ad text (or press Enter to keep unchanged): ";
                    std::getline(std::cin, input);
                    if (!input.empty()) current->data.text = input;

                    std::cout << "Enter new date (YYYY-MM-DD) (or press Enter to keep unchanged): ";
                    std::getline(std::cin, input);

                    if (!input.empty()) {

                        try {
                            current->data.date = normalizeDate(input);
                        }

                        catch (const std::invalid_argument& e) {
                            std::cout << e.what() << std::endl;
                            return;
                        }
                    }

                    std::cout << "Enter new phone number (or press Enter to keep unchanged): ";
                    std::getline(std::cin, input);

                    if (!input.empty()) current->data.phone = input;

                    size_t newSize = calculateRecordSize(current->data);

                    if (newSize < oldSize) {
                        current->data.text.append(oldSize - newSize, '\0');
                    }

                    std::cout << "Record #" << userIndex << " has been updated.\n";
                    return;
                }
                ++currentIndex;
            }
            current = current->next;
        }
        isCompressed = false;

        std::cout << "Invalid record number or the record is deleted." << std::endl;
    }

    void saveRecordsBinary(const std::string& filename) {

        if (isCompressed) {
            std::cout << "Records saved to binary file.\n";
            return;
        }

        std::ofstream file(filename, std::ios::binary | std::ios::trunc);

        if (!file) {
            std::cerr << "Error opening file for writing!" << std::endl;
            return;
        }

        Node* current = head;

        while (current) {
            const Record& record = current->data;

            auto writeField = [&](const std::string& field) {
                size_t length = field.size();
                file.write(reinterpret_cast<const char*>(&length), sizeof(length));
                file.write(field.data(), length);
            };

            file.write(reinterpret_cast<const char*>(&record.isDeleted), sizeof(record.isDeleted));
            writeField(record.category);
            writeField(record.rubric);
            writeField(record.text);
            writeField(record.date);
            writeField(record.phone);

            current = current->next;
        }

        std::cout << "Records saved to binary file.\n";
    }

    void loadRecordsBinary(const std::string& filename) {

        std::ifstream file(filename, std::ios::binary);

        if (!file) {
            std::cerr << "Error opening file for reading!" << std::endl;
            return;
        }

        clear();

        while (file) {

            Record record;

            auto readField = [&](std::string& field) {
                size_t length;
                file.read(reinterpret_cast<char*>(&length), sizeof(length));
                if (file.eof()) return false;
                field.resize(length);
                file.read(&field[0], length);
                return true;
            };

            if (!file.read(reinterpret_cast<char*>(&record.isDeleted), sizeof(record.isDeleted)) ||
                !readField(record.category) || !readField(record.rubric) ||
                !readField(record.text) || !readField(record.date) ||
                !readField(record.phone)) {
                break;
            }

            addRecord(record);
        }
    }

    void compressFile(const std::string& filename) {

        std::ofstream file(filename, std::ios::binary | std::ios::trunc);

        if (!file) {
            std::cerr << "Error opening file for compression!" << std::endl;
            return;
        }

        Node* current = head;
        int recordsWritten = 0;

        while (current) {

            if (!current->data.isDeleted) {
                Record record = current->data;

                record.category = removeTrailingFillers(record.category);
                record.rubric = removeTrailingFillers(record.rubric);
                record.text = removeTrailingFillers(record.text);
                record.date = removeTrailingFillers(record.date);
                record.phone = removeTrailingFillers(record.phone);

                auto writeField = [&](const std::string& field) {
                    size_t length = field.size();
                    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
                    file.write(field.data(), length);
                };

                file.write(reinterpret_cast<const char*>(&record.isDeleted), sizeof(record.isDeleted));
                writeField(record.category);
                writeField(record.rubric);
                writeField(record.text);
                writeField(record.date);
                writeField(record.phone);

                ++recordsWritten;
            }
            current = current->next;
        }

        file.close();
        isCompressed = true;
        std::cout << "File compressed successfully. Records written: " << recordsWritten << std::endl;
    }

    void viewByPages(int pageSize = 5) {

        Node* current = head;
        int totalRecords = 0;

        while (current) {

            if (!current->data.isDeleted) {
                totalRecords++;
            }

            current = current->next;
        }

        int totalPages = (totalRecords + pageSize - 1) / pageSize;

        if (totalPages == 0) {
            std::cout << "No records available to view.\n";
            return;
        }

        int selectedPage = 1;

        while (true) {

            std::cout << "\nTotal Pages: " << totalPages << "\n";
            std::cout << "Enter the page number to view (1 to " << totalPages << ", or 0 to exit): ";
            std::cin >> selectedPage;

            if (selectedPage == 0) {
                break;
            }

            if (selectedPage < 1 || selectedPage > totalPages) {
                std::cout << "Invalid page number. Please try again.\n";
                continue;
            }

            int recordStart = (selectedPage - 1) * pageSize + 1;
            int recordEnd = std::min(selectedPage * pageSize, totalRecords);

            std::cout << "\nDisplaying page " << selectedPage << " (" << recordStart << "-" << recordEnd << "):\n";

            current = head;
            int recordIndex = 0;
            int displayed = 0;

            while (current && displayed < pageSize) {

                if (!current->data.isDeleted) {

                    recordIndex++;

                    if (recordIndex >= recordStart && recordIndex <= recordEnd) {
                        displayRecord(current->data, recordIndex);
                        displayed++;
                    }
                }

                current = current->next;

            }
        }
    }

    void deleteRecord(size_t userIndex) {

        if (!head) {
            std::cout << "No records to delete." << std::endl;
            return;
        }

        Node* current = head;
        size_t currentIndex = 1;

        while (current) {
            if (!current->data.isDeleted) {
                if (currentIndex == userIndex) {
                    current->data.isDeleted = true;
                    std::cout << "Record #" << userIndex << " marked as deleted." << std::endl;
                    return;
                }
                ++currentIndex;
            }
            current = current->next;
        }

        std::cout << "Invalid record number or the record is deleted." << std::endl;
    }

    void searchByCategory(const std::string& category) {

        Node* current = head;
        size_t index = 1;

        while (current) {
            if (!current->data.isDeleted && current->data.category == category) {
                displayRecord(current->data, index);
            }
            current = current->next;
            ++index;
        }
    }

    void searchByKeyword(const std::string& keyword) {

        Node* current = head;
        size_t index = 1;

        while (current) {

            if (!current->data.isDeleted && current->data.text.find(keyword) != std::string::npos) {
                displayRecord(current->data, index);
            }

            current = current->next;
            ++index;
        }
    }

    void sortByDate() {

        if (!head || !head->next) return;

        bool swapped;
        do {

            swapped = false;
            Node* current = head;
            Node* prev = nullptr;

            while (current->next) {

                if (!current->data.isDeleted && !current->next->data.isDeleted &&
                    current->data.date > current->next->data.date) {

                    if (prev) {
                        Node* temp = current->next;
                        current->next = temp->next;
                        temp->next = current;
                        prev->next = temp;
                    }

                    else {
                        Node* temp = current->next;
                        current->next = temp->next;
                        temp->next = current;
                        head = temp;
                    }
                    swapped = true;
                }

                else {
                    prev = current;
                    current = current->next;
                }
            }
        } while (swapped);
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:

    void displayRecord(const Record& record, size_t index) {
        std::cout << "Record #" << index << "\n";
        std::cout << "Category: " << record.category << "\n";
        std::cout << "Rubric: " << record.rubric << "\n";
        std::cout << "Text: " << record.text << "\n";
        std::cout << "Date: " << record.date << "\n";
        std::cout << "Phone: " << record.phone << "\n\n";
    }
};

void displayMenu() {
    std::cout << "1. Add Record\n";
    std::cout << "2. View Records by Pages\n";
    std::cout << "3. Delete Record\n";
    std::cout << "4. Search by Category\n";
    std::cout << "5. Search by Keyword\n";
    std::cout << "6. Sort by Date\n";
    std::cout << "7. Save and Exit\n";
    std::cout << "8. Compress File\n";
    std::cout << "9. Modify Record\n";
    std::cout << "Enter your choice: ";
}

int main() {

    BulletinBoard board;
    const std::string filename = "bulletin_board.dat";

    if (std::filesystem::exists(filename)) {
        board.loadRecordsBinary(filename);
        std::cout << "Records loaded successfully from \"" << filename << "\".\n";
    }

    else {
        std::cout << "No saved file found. Starting with an empty bulletin board.\n";
    }

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                Record record;
                std::cout << "Enter category (Buy/Sell): ";
                std::getline(std::cin, record.category);
                std::cout << "Enter rubric: ";
                std::getline(std::cin, record.rubric);
                std::cout << "Enter ad text: ";
                std::getline(std::cin, record.text);
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::string dateInput;
                std::getline(std::cin, dateInput);

                try {
                    record.date = normalizeDate(dateInput);
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                    continue;
                }

                std::cout << "Enter phone number: ";
                std::getline(std::cin, record.phone);
                board.addRecord(record);
                break;
            }
            case 2: {
                board.viewByPages();
                break;
            }
            case 3: {
                size_t index;
                std::cout << "Enter record number to delete: ";
                std::cin >> index;
                std::cin.ignore();
                board.deleteRecord(index);
                break;
            }
            case 4: {
                std::string category;
                std::cout << "Enter category to search: ";
                std::getline(std::cin, category);
                board.searchByCategory(category);
                break;
            }
            case 5: {
                std::string keyword;
                std::cout << "Enter keyword to search: ";
                std::getline(std::cin, keyword);
                board.searchByKeyword(keyword);
                break;
            }
            case 6: {
                board.sortByDate();
                break;
            }
            case 7: {
                board.saveRecordsBinary("bulletin_board.dat");
                std::cout << "Records saved to binary file.\n";
                break;
            }
            case 8: {
                checkFileSize("bulletin_board.dat");
                board.compressFile("bulletin_board.dat");
                checkFileSize("bulletin_board.dat");
                break;
            }
            case 9: {
                size_t index;
                std::cout << "Enter record number to modify: ";
                std::cin >> index;
                std::cin.ignore();
                board.modifyRecord(index);
                break;
            }
            default:
                if (choice != 7) {
                    std::cout << "Invalid choice. Try again.\n";
                }
                break;
        }
    } while (choice != 7);

    return 0;
}