module com.example.daiquiri {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.simulator to javafx.fxml;
    exports com.example.simulator;
}