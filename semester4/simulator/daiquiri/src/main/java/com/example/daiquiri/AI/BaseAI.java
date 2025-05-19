package com.example.simulator.AI;

import com.example.simulator.Student.Student;

public abstract class BaseAI extends Thread {
    protected int speed;
    public BaseAI(int speed) {
        this.speed = speed;
    }
    public abstract void move();
    }