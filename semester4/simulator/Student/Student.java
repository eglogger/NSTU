package com.example.simulator.Student;

import javafx.scene.image.ImageView;

import java.util.HashSet;
import java.util.Set;
import java.util.Random;

public abstract class Student {
    private static final Set<Integer> generatedIds = new HashSet<>();
    private int id;
    protected ImageView imageView;
    public Student() {
        generateUniqueId();
    }

    private void generateUniqueId() {
        do {
            id = new Random().nextInt(1000);
        } while (generatedIds.contains(this.id));
        generatedIds.add(this.id);
    }

    public int getId() {
        return id;
    }

    public ImageView getImageView() {
        return imageView;
    }
}