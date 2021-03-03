package com.ui.javafx;

import javafx.application.Applicatoion;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.stage.Stage;

public class test {

    public static void main(String[] args){
        System.out.println("");
        System.out.println("Launching JavaFX application");

        Application.launch(BasicFX.class, args);
        Application.launch(BlankFX.class, args);

    }
    
}

class BasicFX extends Application {
    public void init(){
        System.out.println("Inside the Init() method");
    }

    public void start(Stage myStage){
        System.out.println("Inside the Start() method");

        // set title
        myStage.setTitle("Skeleton");

        // creating root
        FlowPane rootNode = new FlowPane();

        // create scene
        Scene myScene = new Scene(rootNode, 300, 300);

        // setting the scent onto the stage
        myStage.setScene(myScene);

        // showing
        myStage.show();
    }

    public void stop(){
        System.out.print("This is the Stop() method");
    }
}
