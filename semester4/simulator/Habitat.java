package com.example.simulator;

import com.example.simulator.Student.Student;
import com.example.simulator.Student.StudentBoy;
import com.example.simulator.Student.StudentGirl;
import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.input.KeyCode;
import javafx.stage.Stage;

import java.time.Duration;
import java.time.Instant;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class Habitat {
    private static Habitat instance;
    private final LinkedList<Student> studentList = new LinkedList<>();
    private final Set<Integer> generatedIds = new HashSet<>();
    private final TreeMap<Integer, Long> birthTimeMap = new TreeMap<>();
    private final TextField boyLifeTimeField;
    private final TextField girlLifeTimeField;
    private final Pane simulationPane;
    private final List<Student> students;
    private final Text timerText;
    private final Button startButton;
    private final Button stopButton;
    private Instant simulationStartTime;
    private boolean isSimulationRunning;
    private Timer simulationTimer;
    private int boySpawnDelay = 3;
    private int girlSpawnDelay = 1;
    private long boyLifeTime = 2;
    private long girlLifeTime = 3;
    private Instant dialogOpenTime;
    private double boyProbability = 0.8;
    private double girlProbability = 0.5;
    private Duration simulationDuration;
    private int boyCount = 0;
    private int girlCount = 0;
    private boolean isTimerVisible;
    private RadioButton showTimerRadioButton;
    private Instant simulationPauseTime;
    private RadioButton hideTimerRadioButton;
    private ToggleGroup toggleGroup;
    private CheckBox showInfoCheckbox;
    private long lastBoySpawnTime = 0;
    private long lastGirlSpawnTime = 0;

    private final TextField boySpawnDelayField;
    private final TextField girlSpawnDelayField;
    private final ComboBox<Integer> boyProbabilityComboBox;
    private final Slider girlProbabilitySlider;
    private Habitat(Stage primaryStage) {

        this.simulationPane = new Pane();
        this.simulationPane.setPrefSize(800, 600);
        this.students = new ArrayList<>();
        this.timerText = new Text("Elapsed time: ");
        this.startButton = new Button("Start");
        this.stopButton = new Button("Stop");
        this.isSimulationRunning = false;
        this.simulationStartTime = Instant.now();
        this.isTimerVisible = true;

        HBox buttonBox = new HBox(startButton, stopButton);
        buttonBox.setSpacing(10);

        HBox hbox = new HBox(buttonBox, timerText);
        hbox.setSpacing(10);

        primaryStage.widthProperty().addListener((obs, oldVal, newVal) -> {
            double width = newVal.doubleValue();
            double height = primaryStage.getHeight();
            simulationPane.setPrefSize(width, height);
        });

        primaryStage.heightProperty().addListener((obs, oldVal, newVal) -> {
            double width = primaryStage.getWidth();
            double height = newVal.doubleValue();
            simulationPane.setPrefSize(width, height);
        });

        StackPane stackPane = new StackPane(simulationPane, hbox);
        stackPane.setStyle("-fx-padding: 10px;");
        StackPane.setAlignment(hbox, Pos.CENTER_RIGHT);

        MenuBar menuBar = new MenuBar();
        Menu fileMenu = new Menu("File");
        MenuItem Start_menu = new MenuItem("Start");
        MenuItem Stop_menu = new MenuItem("Stop");
        MenuItem showTimerItem = new MenuItem("Show Timer");
        MenuItem hideTimerItem = new MenuItem("Hide Timer");
        MenuItem showInfoItem = new MenuItem("Show Info");
        fileMenu.getItems().addAll(Start_menu, Stop_menu, showTimerItem, hideTimerItem, showInfoItem);
        menuBar.getMenus().add(fileMenu);

        Scene scene = new Scene(new VBox(menuBar, stackPane), 1100, 700);
        primaryStage.setScene(scene);

        showTimerRadioButton = new RadioButton("Show Timer");
        hideTimerRadioButton = new RadioButton("Hide Timer");

        showInfoCheckbox = new CheckBox("Show Info");

        toggleGroup = new ToggleGroup();
        showTimerRadioButton.setToggleGroup(toggleGroup);
        hideTimerRadioButton.setToggleGroup(toggleGroup);

        showTimerRadioButton.setOnAction(event -> toggleTimerVisibility());
        hideTimerRadioButton.setOnAction(event -> toggleTimerVisibility());

        VBox radioButtonsBox = new VBox(showTimerRadioButton, hideTimerRadioButton);
        radioButtonsBox.setSpacing(5);
        hbox.getChildren().add(radioButtonsBox);

        hbox.getChildren().add(showInfoCheckbox);
        showTimerRadioButton.setSelected(true);

        timerText.setFont(Font.font("Arial", FontWeight.BOLD, 16));
        startButton.setOnAction(e -> startSimulation());
        stopButton.setOnAction(e -> stopSimulation());

        primaryStage.getScene().setOnKeyPressed(event -> {
            if (event.getCode() == KeyCode.B) {
                startSimulation();
            } else if (event.getCode() == KeyCode.E) {
                stopSimulation();
            } else if (event.getCode() == KeyCode.T) {
                toggleTimerVisibility();
            }
        });

        Start_menu.setOnAction(event -> startSimulation());
        Stop_menu.setOnAction(event -> stopSimulation());
        showTimerItem.setOnAction(event -> showTimer());
        hideTimerItem.setOnAction(event -> hideTimer());
        showInfoItem.setOnAction(event -> showInfoCheckbox.setSelected(!showInfoCheckbox.isSelected()));

        boySpawnDelayField = new TextField(String.valueOf(boySpawnDelay));
        girlSpawnDelayField = new TextField(String.valueOf(girlSpawnDelay));
        boyLifeTimeField = new TextField(String.valueOf(boyLifeTime));
        girlLifeTimeField = new TextField(String.valueOf(girlLifeTime));

        boyProbabilityComboBox = new ComboBox<>();
        for (int probability = 0; probability <= 100; probability += 10) {
            boyProbabilityComboBox.getItems().add(probability);
        }
        boyProbabilityComboBox.setValue((int)(boyProbability * 100));

        girlProbabilitySlider = new Slider(0, 100, girlProbability * 100);
        girlProbabilitySlider.setBlockIncrement(10);
        girlProbabilitySlider.setMajorTickUnit(10);
        girlProbabilitySlider.setMinorTickCount(0);
        girlProbabilitySlider.setShowTickLabels(true);
        girlProbabilitySlider.setShowTickMarks(true);

        VBox controlBox = new VBox(
                new Label("Boy Spawn Delay: "), boySpawnDelayField,
                new Label("Girl Spawn Delay: "), girlSpawnDelayField,
                new Label("Boy Probability: "), boyProbabilityComboBox,
                new Label("Girl Probability: "), girlProbabilitySlider,
                new Label("Boy Life Time: "), boyLifeTimeField,
                new Label("Girl Life Time: "), girlLifeTimeField
        );
        Button objectsButton = new Button("Current Objects");
        objectsButton.setOnAction(event -> showCurrentObjectsDialog(primaryStage, birthTimeMap));
        controlBox.getChildren().addAll(objectsButton);

        controlBox.setSpacing(10);
        controlBox.setPadding(new Insets

                (0, 0, 20, 0));
        controlBox.setMinWidth(250);
        hbox.getChildren().add(controlBox);

        boyProbabilityComboBox.setOnAction(event -> boyProbability = boyProbabilityComboBox.getValue() / 100.0);
        girlProbabilitySlider.valueProperty().addListener((obs, oldVal, newVal) -> girlProbability = newVal.doubleValue() / 100.0);

    }

    private void showTimer() {
        if (!isTimerVisible) {
            toggleTimerVisibility();
        }
    }

    private void hideTimer() {
        if (isTimerVisible) {
            toggleTimerVisibility();
        }
    }

    private void showAlertWithSimulationInfo() {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Simulation Info");
        alert.setHeaderText(null);

        TextArea textArea = new TextArea();
        textArea.setEditable(false);
        textArea.setWrapText(true);

        StringBuilder message = new StringBuilder();
        message.append("Boys: ").append(boyCount).append("\n");
        message.append("Girls: ").append(girlCount).append("\n");
        message.append("Elapsed time: ").append(getSimulationTime()).append("\n");
        textArea.setText(message.toString());

        alert.getDialogPane().setContent(textArea);
        alert.getButtonTypes().clear();
        alert.getButtonTypes().addAll(ButtonType.OK, ButtonType.CANCEL);

        alert.showAndWait().ifPresent(buttonType -> {
            if (buttonType == ButtonType.OK) {
                simulationPane.getChildren().clear();
                startButton.setDisable(false);
                stopButton.setDisable(true);
                boyCount = 0;
                girlCount = 0;
                updateTimer();
            } else {
                isSimulationRunning = true;
                simulationStartTime = simulationStartTime.plus(Duration.between(simulationPauseTime, Instant.now()));
                startTimer();
                stopButton.setDisable(false);
                startButton.setDisable(true);
            }
        });
    }
    private void startSimulation() {

        try {
            boySpawnDelay = Integer.parseInt(boySpawnDelayField.getText());
            girlSpawnDelay = Integer.parseInt(girlSpawnDelayField.getText());
            boyLifeTime = Integer.parseInt(boyLifeTimeField.getText());
            girlLifeTime = Integer.parseInt(girlLifeTimeField.getText());

            if (boySpawnDelay < 0 || girlSpawnDelay < 0 || boyLifeTime < 0 || girlLifeTime < 0) {
                throw new NumberFormatException();
            }

            if (!isSimulationRunning) {
                isSimulationRunning = true;
                simulationStartTime = Instant.now();
                startTimer();
                removeSimulationResult();
                stopButton.setDisable(false);
                startButton.setDisable(true);
            }
        } catch (NumberFormatException e) {

            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setHeaderText("Invalid input!");
            alert.setContentText("Input must be a positive integer.");

            if(!boySpawnDelayField.getText().matches("\\d+") || boySpawnDelay < 0)
            {
                boySpawnDelayField.setText("3");
                boySpawnDelay = 3;
            }
            if(!girlSpawnDelayField.getText().matches("\\d+") || girlSpawnDelay < 0)
            {
                girlSpawnDelayField.setText("1");
                girlSpawnDelay = 1;
            }
            if(!boyLifeTimeField.getText().matches("\\d+") || boyLifeTime < 0)
            {
                boyLifeTimeField.setText("2");
                boyLifeTime = 2;
            }
            if(!girlLifeTimeField.getText().matches("\\d+") || girlLifeTime < 0)
            {
                girlLifeTimeField.setText("3");
                girlLifeTime = 3;
            }

            alert.showAndWait();
        }
    }
    public void stopSimulation() {
        if (isSimulationRunning) {
            isSimulationRunning = false;
            stopTimer();
            simulationPauseTime = Instant.now();

            long elapsedSeconds = Duration.between(simulationStartTime, simulationPauseTime).getSeconds();
            lastBoySpawnTime -= elapsedSeconds;
            lastGirlSpawnTime -= elapsedSeconds;

            if (showInfoCheckbox.isSelected()) {
                showAlertWithSimulationInfo();
            } else {
                Platform.runLater(() -> {
                    simulationPane.getChildren().clear();
                    startButton.setDisable(false);
                    stopButton.setDisable(true);
                });
                students.clear();
                generatedIds.clear();
                birthTimeMap.clear();
                studentList.clear();
                boyCount = 0;
                girlCount = 0;
                updateTimer();
            }
        }
    }

    private long getSimulationDuration(){
        simulationDuration = Duration.between(simulationStartTime, Instant.now());

        return simulationDuration.getSeconds();
    }

    private String getSimulationTime() {
        Duration duration;
        if (isSimulationRunning) {
            duration = Duration.between(simulationStartTime, Instant.now());
        } else {
            duration = Duration.between(simulationStartTime, simulationPauseTime);
        }
        long seconds = duration.getSeconds();
        long minutes = seconds / 60;
        seconds %= 60;
        return minutes + " minutes " + seconds + " seconds";
    }

    private void removeSimulationResult() {
        simulationPane.getChildren().removeIf(node ->
                node instanceof Text && ((Text) node).getText().startsWith("Result:"));
    }

    private void showCurrentObjectsDialog(Stage primaryStage, TreeMap<Integer, Long> birthTimeMap) { //Модальное окно с информацией о текущих объектах
        pauseTimer();
        dialogOpenTime = Instant.now();

        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Current Objects");
        alert.setHeaderText(null);

        TextArea textArea = new TextArea();
        textArea.setEditable(false);
        textArea.setWrapText(true);

        StringBuilder message = new StringBuilder();
        birthTimeMap.forEach((objectId, birthTime) -> {
            message.append("ID: ").append(objectId).append(", Birth time: ").append(birthTime).append("\n");
        });
        textArea.setText(message.toString());

        alert.getDialogPane().setContent(textArea);
        alert.getButtonTypes().clear();
        alert.getButtonTypes().addAll(ButtonType.CLOSE);

        alert.initOwner(primaryStage);
        alert.showAndWait();

        resumeTimer();
    }

    private void pauseTimer() {
        stopTimer();
    }

    private void resumeTimer() {
        startTimer();
        if (dialogOpenTime != null) {
            simulationStartTime = simulationStartTime.plus(Duration.between(dialogOpenTime, Instant.now()));
            dialogOpenTime = null;
        }
    }
    private void startTimer() {
        simulationTimer = new Timer();
        simulationTimer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                if (!isSimulationRunning) {
                    return;
                }
                long elapsedSeconds = Duration.between(simulationStartTime, Instant.now()).getSeconds();
                if (elapsedSeconds - lastBoySpawnTime >= boySpawnDelay) {
                    Platform.runLater(() -> {
                        if (Math.random() < boyProbability) {
                            generateStudentBoy();
                            boyCount++;
                        }
                    });
                    lastBoySpawnTime = elapsedSeconds;
                }
                if (elapsedSeconds - lastGirlSpawnTime >= girlSpawnDelay) {
                    Platform.runLater(() -> {
                        if (Math.random() < girlProbability) {
                            generateStudentGirl();
                            girlCount++;
                        }
                    });
                    lastGirlSpawnTime = elapsedSeconds;
                }
                Platform.runLater(() -> {
                    updateTimer();
                    removeExpiredStudents();
                });
            }
        }, 0, 1000);
    }
    private void removeExpiredStudents() {
        long currentSimulationTime = getSimulationDuration();

        Iterator<Student> iterator = students.iterator();
        while (iterator.hasNext()) {
            Student student = iterator.next();
            Long birthTime = birthTimeMap.get(student.getId());

            if (birthTime == null) {
                iterator.remove();
                continue;
            }

            long elapsedTime = currentSimulationTime - birthTime;

            if ((student instanceof StudentBoy && elapsedTime >= boyLifeTime) ||
                    (student instanceof StudentGirl && elapsedTime >= girlLifeTime)) {
                Platform.runLater(() -> {
                    simulationPane.getChildren().remove(student.getImageView());
                });
                iterator.remove();
                generatedIds.remove(student.getId());
                birthTimeMap.remove(student.getId());
                studentList.remove(student);
            }
        }
    }
    private void stopTimer() {
        if (simulationTimer != null) {
            simulationTimer.cancel();
            simulationTimer = null;
        }
    }
    private void generateStudentBoy() {
        StudentBoy studentBoy = new StudentBoy();
        addStudentToScene(studentBoy);
        studentList.add(studentBoy);
        birthTimeMap.put(studentBoy.getId(), getSimulationDuration());
    }
    private void generateStudentGirl() {
        StudentGirl studentGirl = new StudentGirl();
        addStudentToScene(studentGirl);
        studentList.add(studentGirl);
        birthTimeMap.put(studentGirl.getId(), getSimulationDuration());
    }

    private void addStudentToScene(Student student) {
        if (generatedIds.contains(student.getId())) {
            if (student instanceof StudentBoy) {
                generateStudentBoy();
            } else if (student instanceof StudentGirl) {
                generateStudentGirl();
            }
            return;
        }

        ImageView imageView = student.getImageView();
        double maxX = simulationPane.getWidth() - imageView.getFitWidth() - 340;
        double maxY = simulationPane.getHeight() - imageView.getFitHeight();
        double randomX = ThreadLocalRandom.current().nextDouble(0, maxX);
        double randomY = ThreadLocalRandom.current().nextDouble(50, maxY);
        imageView.setX(randomX);
        imageView.setY(randomY);
        simulationPane.getChildren().add(imageView);
        students.add(student);
        generatedIds.add(student.getId());
    }

    private void updateTimer() {
        if (isSimulationRunning) {
            Duration duration = Duration.between(simulationStartTime, Instant.now());
            long seconds = duration.getSeconds();
            long minutes = seconds / 60;
            seconds %= 60;
            timerText.setText("Elapsed time: " + minutes + " minutes " + seconds + " seconds");
        }
    }

    private void toggleTimerVisibility() {
        isTimerVisible = !isTimerVisible;
        timerText.setVisible(isTimerVisible);
        if (isTimerVisible) {
            showTimerRadioButton.setSelected(true);
        } else {
            hideTimerRadioButton.setSelected(true);
        }
        updateTimer();
    }
    public static synchronized Habitat getInstance(Stage primaryStage) {
        if (instance == null) {
            instance = new Habitat(primaryStage);
        }
        return instance;
    }
}