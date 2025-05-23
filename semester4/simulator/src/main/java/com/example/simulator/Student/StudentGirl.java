package com.example.simulator.Student;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;

import java.io.*;

public class StudentGirl extends Student implements IBehaviour {
    transient private static Image girlImage; // Статическая переменная для хранения изображения
    private long birthTime;
    public double centerX;
    public double centerY;
    public boolean isCentred = false;

    public StudentGirl(Pane simulationPane, int imgWidth, int imgHeight) {
        super();
        this.imgWidth = imgWidth;
        this.imgHeight = imgHeight;
        if (girlImage == null) {
            InputStream inputStream = getClass().getResourceAsStream("/com/example/simulator/girl.png");
            if (inputStream != null) {
                girlImage = new Image(inputStream);
            } else {
                System.err.println("Не удалось загрузить изображение");
            }
        }
        imageView = new ImageView(girlImage);
        imageView.setFitWidth(imgWidth);
        imageView.setFitHeight(imgHeight);
/*        double maxX = simulationPane.getWidth() - imgWidth;
        double maxY = simulationPane.getHeight() - imgHeight;
        coordX = ThreadLocalRandom.current().nextDouble(0, maxX);
        coordY = ThreadLocalRandom.current().nextDouble(0, maxY);
        imageView.setX(coordX);
        imageView.setY(coordY);*/
    }
}

