package com.ui.javafx;

import javafx.application.Application;
import javafx.scene.layout.FlowPane;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

public class DynamicAddFX extends Application {

    // overwriting the init() method
    public void init() {
        System.out.println("Inside the Init() method");
    }

    // overwriting the run() method
    public void start(Stage myStage) {
        System.out.println("Inside the start() method");

        // Give the stage a title.
        myStage.setTitle("JavaFX Skeleton.");

        // Create a root node. In this case, a flow layout
        // is used, but several alternatives exist.
        FlowPane rootNode = new FlowPane();

        // Create a scene.
        Scene myScene = new Scene(rootNode, 300, 200);

        // Set the scene on the stage.
        myStage.setScene(myScene);

        // creating label
        Label myLabel = new Label("JavaFX Dynamically Added Label");

        // Add label
        rootNode.getChildren().add(myLabel);

        // Show the stage and its scene.
        myStage.show();
    }

    // overwriting the stop() method
    public void stop() {
        System.out.println("Inside the stop() method");
    }
}
