package com.example.simulator;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;

public class HabitatConsoleController {
    @FXML
    private TextField commandTextField;

    @FXML
    private TextArea responseTextArea;

    @FXML
    private Button executeButton;
    @FXML
    private HBox hbox;
    private Controller controller;

    public void initialize() {
        commandTextField.setPromptText("Enter the command...");

        executeButton.setOnAction(event -> {
            String command = commandTextField.getText();
            responseTextArea.appendText(command + "\n");
            String response = executeCommand(command);
            responseTextArea.appendText(response);
            commandTextField.clear();
        });

        HBox.setHgrow(commandTextField, Priority.ALWAYS);
        HBox.setHgrow(executeButton, Priority.NEVER);
        executeButton.setMinWidth(Button.USE_PREF_SIZE);

        responseTextArea.setEditable(false);
        responseTextArea.setPrefRowCount(100);
    }
    public void setController(Controller controller){
        this.controller = controller;
    }

    private String executeCommand(String command) {
        if ("timer_show".equalsIgnoreCase(command)) {
            if(!controller.isTimerVisible()) {
                controller.consoleShowTimer();
                return "Command completed\n";
            }else {
                return "Timer is already shown\n";
            }
        } else if ("timer_hide".equalsIgnoreCase(command)) {
            if(controller.isTimerVisible()) {
                controller.consoleHideTimer();
                return "Command completed\n";
            }else {
                return "Timer is already hidden\n";
            }
        } else {
            return "Unknown command\n";
        }
    }
}
