module com.example.daiquiri {
    requires javafx.controls;
    requires javafx.fxml;
    requires org.apache.commons.lang3;


    opens com.example.simulator to javafx.fxml;
    exports com.example.simulator;
}