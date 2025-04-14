package com.example.simulator;

import javafx.application.Application;
import javafx.stage.Stage;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) {
        Habitat habitat = Habitat.getInstance(primaryStage);
        primaryStage.setTitle("Simulation");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
