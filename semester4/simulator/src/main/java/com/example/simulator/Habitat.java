package com.example.simulator;

import com.example.simulator.Student.Student;
import com.example.simulator.Student.StudentBoy;
import com.example.simulator.Student.StudentGirl;
import javafx.animation.AnimationTimer;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

public class Habitat {
    private final Group root;
    private final List<Student> students;
    private final Text timerText;
    private Instant simulationStartTime;
    private boolean isSimulationRunning;
    private AnimationTimer simulationTimer;
    private int boySpawnDelay = 3;
    private int girlSpawnDelay = 1;
    double boyProbability = 0.8;
    double girlProbability = 0.5;
    int boyCount = 0;
    int girlCount = 0;
    private boolean isTimerVisible;

    public Habitat(Stage primaryStage) {
        this.root = new Group();
        this.students = new ArrayList<>();
        this.timerText = new Text(10, 20, "");
        this.isSimulationRunning = false;
        this.simulationStartTime = Instant.now();
        this.isTimerVisible = true;

        Scene scene = new Scene(root, 800, 600);
        primaryStage.setScene(scene);

        timerText.setFont(Font.font("Arial", FontWeight.BOLD, 16));
        root.getChildren().add(timerText);

        primaryStage.getScene().setOnKeyPressed(event -> {
            if (event.getCode() == KeyCode.B) {
                startSimulation();
            } else if (event.getCode() == KeyCode.E) {
                stopSimulation();
            } else if (event.getCode() == KeyCode.T) {
                toggleTimerVisibility();
            }
        });
    }

    public void startSimulation() {
        if (!isSimulationRunning) {
            isSimulationRunning = true;
            simulationStartTime = Instant.now();
            startTimer();
            removeSimulationResult();
        }
    }

    public void stopSimulation() {
        if (isSimulationRunning) {
            isSimulationRunning = false;
            stopTimer();
            root.getChildren().removeIf(node -> node != timerText);
            students.clear();
            showSimulationResult();
            girlCount = 0;
            boyCount = 0;
            updateTimer();
        }
    }

    private void removeSimulationResult() {
        root.getChildren().removeIf(node ->
                node instanceof Text && ((Text) node).getText().startsWith("Simulation Result:"));
    }

    private void showSimulationResult() {
        Text resultText = new Text();
        resultText.setFont(Font.font("Arial", FontWeight.BOLD, 20));
        resultText.setFill(Color.BLACK);
        resultText.setX(10);
        resultText.setY(50);
        String resultMessage = String.format("Simulation Result:\n"
                        + "Boys: %d\n"
                        + "Girls: %d\n",
                boyCount, girlCount);

        resultText.setText(resultMessage);
        root.getChildren().add(resultText);
    }
    private void startTimer() {
        simulationTimer = new AnimationTimer() {
            private long lastBoySpawnTime = 0;
            private long lastGirlSpawnTime = 0;

            @Override
            public void handle(long now) {
                if (!isSimulationRunning) {
                    return;
                }

                long elapsedSeconds = Duration.between(simulationStartTime, Instant.now()).getSeconds();
                if (elapsedSeconds - lastBoySpawnTime >= boySpawnDelay) {
                    if (Math.random() < boyProbability) {
                        generateStudentBoy();
                        boyCount++;
                    }
                    lastBoySpawnTime = elapsedSeconds;
                }
                if (elapsedSeconds - lastGirlSpawnTime >= girlSpawnDelay) {
                    if (Math.random() < girlProbability) {
                        generateStudentGirl();
                        girlCount++;
                    }
                    lastGirlSpawnTime = elapsedSeconds;
                }
                updateTimer();
            }
        };
        simulationTimer.start();
    }

    private void stopTimer() {
        simulationTimer.stop();
    }

    private void generateStudentBoy() {
        StudentBoy studentBoy = new StudentBoy();
        addStudentToScene(studentBoy);
    }

    private void generateStudentGirl() {
        StudentGirl studentGirl = new StudentGirl();
        addStudentToScene(studentGirl);
    }

    private void addStudentToScene(Student student) {
        ImageView imageView = student.getImageView();
        double maxX = root.getScene().getWidth() - imageView.getFitWidth();
        double maxY = root.getScene().getHeight() - imageView.getFitHeight();
        double randomX = ThreadLocalRandom.current().nextDouble(0, maxX);
        double randomY = ThreadLocalRandom.current().nextDouble(25, maxY);
        ((ImageView) imageView).setX(randomX);
        imageView.setY(randomY);
        root.getChildren().add(imageView);
        students.add(student);
    }

    private void updateTimer() {
        if (isSimulationRunning) {
            Duration duration = Duration.between(simulationStartTime, Instant.now());
            long seconds = duration.getSeconds();
            long minutes = seconds / 60;
            seconds %= 60;
            timerText.setText("Simulation time: " + minutes + " minutes " + seconds + " seconds");
        }
    }

    private void toggleTimerVisibility() {
        isTimerVisible = !isTimerVisible;
        if (isTimerVisible) {
            timerText.setVisible(true);
            updateTimer();
        } else {
            timerText.setVisible(false);
        }
    }
}