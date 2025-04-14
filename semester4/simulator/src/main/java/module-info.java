module com.example.simulator {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;


    opens com.example.simulator to javafx.fxml;
    exports com.example.simulator;
}