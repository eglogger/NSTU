package com.example.simulator.Student;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class StudentGirl extends Student implements IBehaviour {
    public StudentGirl() {
        try {
            Image image = new Image(new FileInputStream("src/main/resources/com/example/simulator/girl.png"));
            imageView = new ImageView(image);
            imageView.setFitWidth(225);
            imageView.setFitHeight(225);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
