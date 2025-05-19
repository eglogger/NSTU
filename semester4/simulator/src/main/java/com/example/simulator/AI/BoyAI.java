package com.example.simulator.AI;

import com.example.simulator.Student.Student;
import com.example.simulator.Student.StudentBoy;
import javafx.scene.layout.Pane;

import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

public class BoyAI extends BaseAI {

    private List<Student> studentList;
    private int changeDirectionTime;
    private final Pane simulationPane;
    private boolean isRunning;
    public BoyAI(int changeDirectionTime, int speed, List<Student> studentList, Pane simulationPane) {
        super(speed);
        this.changeDirectionTime = changeDirectionTime;
        this.studentList = studentList;
        this.simulationPane = simulationPane;
        this.isRunning = true;
    }
    public void stopAI() {
        isRunning = false;
    }
    public void resumeAI() {
        isRunning = true;
        synchronized (this) {
            notify();
        }
    }
    @Override
    public void run() {
        while (isRunning) {
            move();
           try {
               Thread.sleep(100); // Пауза между шагами
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    @Override
    public void move() {
        for (Student student : studentList) {
            if (student instanceof StudentBoy) {
                StudentBoy studentBoy = (StudentBoy) student;
                long currentTime = System.currentTimeMillis();
                if(!studentBoy.isInit){
                    studentBoy.isInit = true;
                    studentBoy.setAngle(Math.toRadians(ThreadLocalRandom.current().nextDouble(0, 360)));
                    studentBoy.lastMoveTime = System.currentTimeMillis();
                }
                if (currentTime - studentBoy.lastMoveTime >= (changeDirectionTime * 1000)) {
                    studentBoy.setAngle(Math.toRadians(ThreadLocalRandom.current().nextDouble(0, 360)));
                    studentBoy.lastMoveTime = System.currentTimeMillis();
                }
                double currentX = studentBoy.getImageView().getX();
                double currentY = studentBoy.getImageView().getY();
                double newX = currentX + (speed * Math.cos(studentBoy.getAngle()) / 10);
                double newY = currentY + (speed * Math.sin(studentBoy.getAngle()) / 10);
                double objectWidth = student.getImageView().getFitWidth();
                double objectHeight = student.getImageView().getFitHeight();

                if (newX < 0) {
                    newX = 0;
                } else if (newX > simulationPane.getWidth() - objectWidth) {
                    newX = simulationPane.getWidth() - objectWidth;
                }

                if (newY < 0) {
                    newY = 0;
                } else if (newY > simulationPane.getHeight() - objectHeight) {
                    newY = simulationPane.getHeight() - objectHeight;
                }
                studentBoy.moveTo(newX, newY);
            }
        }
    }
}
