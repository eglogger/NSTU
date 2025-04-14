package com.example.simulator;

import javafx.application.Application;
import javafx.stage.Stage;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) {
        com.example.simulator.Habitat habitat = new com.example.simulator.Habitat(primaryStage);
        primaryStage.setTitle("Simulation");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
