package com.ui.javafx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;

public class BlankFX extends Application {

    // overwriting the run() method
    public void start(Stage myStage) {
        System.out.println("\n\nA Simple Blank Application : \n\n");

        // setting the name of our Stage
        myStage.setTitle("JavaFX Blank");

        // setting up the root container of the stage
        FlowPane root = new FlowPane();

        // setting up the scene, and constructing the object using root
        Scene scene = new Scene(root, 300, 200);

        // Adding the scene to our stage
        myStage.setScene(scene);

        // outputting our stage
        myStage.show();
    }
}
