#include "queuearray.h"
#include <stdexcept>

QueueArray::QueueArray(int size) : Array(size), frontIndex(0) {}

QueueArray::QueueArray(const QueueArray& other) : Array(other), frontIndex(other.frontIndex) {}

void QueueArray::enqueue(int elem) {

    if (getCurrentSize() >= getMaxSize()) {
        throw std::overflow_error("Cannot enqueue: Queue is full.");
    }

    add(elem);
}

int QueueArray::dequeue() {

    if (getCurrentSize() == 0) {
        throw std::underflow_error("Cannot dequeue: Queue is empty.");
    }

    int elem = get(frontIndex);
    remove(frontIndex);

    return elem;
}

int QueueArray::front() const {

    if (getCurrentSize() == 0) {
        throw std::underflow_error("Cannot get front: Queue is empty.");
    }

    return get(frontIndex);
}
