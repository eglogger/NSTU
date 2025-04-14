package com.example.simulator.Student;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class StudentGirl extends com.example.simulator.Student.Student implements IBehaviour {
    private long birthTime;

    public StudentGirl() {
        super();
        try {
            Image image = new Image(new FileInputStream("src/main/resources/com/example/simulator/girl.png"));
            imageView = new ImageView(image);
            imageView.setFitWidth(200);
            imageView.setFitHeight(200);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
