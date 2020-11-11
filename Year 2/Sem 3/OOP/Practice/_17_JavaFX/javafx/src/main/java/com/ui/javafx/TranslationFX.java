package com.ui.javafx;

import javafx.animation.Timeline;
import javafx.animation.TranslateTransition;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.util.Duration;
// import javafx.scene.Group;
import javafx.scene.layout.*;
import javafx.scene.Scene;
// import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class TranslationFX extends Application {

    // overriting run() method
    public void start(Stage myStage) {
        System.out.println("\n\nA Simple Translation Application : \n\n");

        // setting the title of the stage
        myStage.setTitle("JavaFX Translation");

        // creating root node container
        StackPane root = new StackPane();

        // creating new scene and giving it the root in the constructor
        Scene scene = new Scene(root, 500, 300);

        // creating Label
        Label label1 = new Label(
                "TRANSLATION APP. This animation seem like a single line that loops but it is actually 2 lines.");
        Label label2 = new Label(
                "Translation App. This animation seem like a single line that loops but it is actually 2 lines.");

        // creating animations
        TranslateTransition trans1 = new TranslateTransition(Duration.seconds(15), label1);
        trans1.setFromX(0);
        trans1.setToX(492);
        trans1.setCycleCount(Timeline.INDEFINITE);

        TranslateTransition trans2 = new TranslateTransition(Duration.seconds(15), label2);
        trans2.setFromX(-492);
        trans2.setToX(0);
        trans2.setCycleCount(Timeline.INDEFINITE);

        // running transition
        trans1.play();
        trans2.play();

        // adding button to the parent root
        root.getChildren().addAll(label1, label2);

        // setting the positions of the button and the label
        StackPane.setAlignment(label1, Pos.CENTER);
        StackPane.setAlignment(label2, Pos.CENTER);

        // setting up our scene on the stage
        myStage.setScene(scene);

        // showing/outputing our stage
        myStage.show();
    }

}
