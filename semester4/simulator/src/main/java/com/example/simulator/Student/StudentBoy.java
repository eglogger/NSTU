package com.example.simulator.Student;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;

import java.io.InputStream;

public class StudentBoy extends Student implements IBehaviour {
    transient private static Image boyImage;
    private long birthTime;
    public long lastMoveTime;
    public boolean isInit = false;
    public StudentBoy(Pane simulationPane, int imgWidth, int imgHeight) {
        super();
        this.imgWidth = imgWidth;
        this.imgHeight = imgHeight;
        if (boyImage == null) {
            InputStream inputStream = getClass().getResourceAsStream("/com/example/simulator/boy.png");
            if (inputStream != null) {
                boyImage = new Image(inputStream);
            } else {
                System.err.println("Error loading boy picture.");
            }
        }
        imageView = new ImageView(boyImage);
        imageView.setFitWidth(imgWidth);
        imageView.setFitHeight(imgHeight);
    }
}
