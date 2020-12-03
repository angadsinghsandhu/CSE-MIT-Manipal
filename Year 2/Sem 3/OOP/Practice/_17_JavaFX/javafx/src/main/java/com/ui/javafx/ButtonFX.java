package com.ui.javafx;

import java.util.concurrent.TimeUnit;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.event.*;
// import javafx.scene.Group;
import javafx.scene.layout.*;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class ButtonFX extends Application {

    // overriting run() method
    public void start(Stage myStage) {
        System.out.println("\n\nA Simple Button Application : \n\n");

        // setting the title of the stage
        myStage.setTitle("JavaFX Button");

        // creating root node container
        StackPane root = new StackPane();

        // creating new scene and giving it the root in the constructor
        Scene scene = new Scene(root, 400, 400);

        // creating Button and Label
        Button btn = new Button("Click Here");
        Label label = new Label("Button App");

        // adding event to button press
        btn.setOnAction(new EventHandler<ActionEvent>() {

            // adding handle method
            public void handle(ActionEvent ae) {

                // changing label on button press
                label.setText("Button Pressed");

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                label.setText("Button App");

            }
        });

        // adding button to the parent root
        root.getChildren().addAll(btn, label);

        // setting the positions of the button and the label
        StackPane.setAlignment(btn, Pos.CENTER);
        StackPane.setAlignment(label, Pos.TOP_CENTER);

        // setting up our scene on the stage
        myStage.setScene(scene);

        // showing/outputing our stage
        myStage.show();
    }

}
