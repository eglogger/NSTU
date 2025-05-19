package com.example.simulator.AI;

public abstract class BaseAI extends Thread {
    protected int speed;
    public BaseAI(int speed) {
        this.speed = speed;
    }
    public abstract void move();
    }