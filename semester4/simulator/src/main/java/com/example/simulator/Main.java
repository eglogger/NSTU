package com.example.simulator;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.image.Image;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) {
        Image icon = null;
        try {
            icon = new Image(new FileInputStream("src/main/resources/com/example/simulator/icon.png"));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        primaryStage.getIcons().add(icon);
        Habitat habitat = Habitat.getInstance(primaryStage);
        primaryStage.setTitle("Simulation");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
