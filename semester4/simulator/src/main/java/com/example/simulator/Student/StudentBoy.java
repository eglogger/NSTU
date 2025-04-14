package com.example.simulator.Student;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class StudentBoy extends Student implements IBehaviour {
    public StudentBoy() {
        try {
            Image image = new Image(new FileInputStream("src/main/resources/com/example/simulator/boy.png"));
            imageView = new ImageView(image);
            imageView.setFitWidth(200);
            imageView.setFitHeight(200);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
