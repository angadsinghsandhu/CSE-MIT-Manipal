package com.ui.javafx;

import javafx.application.Application;

/*
	IMPORTANT, PLS READ BEFORE EXECUTING JAVAFX CODE :

  Hi, this is Angad. The one who wrote all this code

	As I am using Java JDK 13, JavaFX binaries are not very compatible
	hence I am using this gradle project instead of directly running it.

	- This is Gradle Project which was created using Spring-Boot, you
	  can learn how to create these projects using the link given below
	  "https://www.youtube.com/watch?v=5mpHejytgFE&ab_channel=DanVega"
	  "https://code.visualstudio.com/docs/java/java-spring-boot"

	- I am not directly running Gradle Build, Insted I am using Gradle Tasks
	  to run my application, you can do that using :
	  "https://www.youtube.com/watch?v=nKIMGH0l3Wo&ab_channel=PaulGestwicki"

	- If you are like me and running gradle on vscode you will need this 
	  Extension to run Gradle Tasks :
	  "https://marketplace.visualstudio.com/items?itemName=richardwillis.vscode-gradle"
*/

public class Main {
    public static void main(String[] args) {
        System.out.println("\n");
        System.out.println("Launching JavaFX application.");

        /*
         * ============================== all the following code blocks are different
         * applications, un-comment them to execute them ===============================
         */

        // // Program 0 : BASIC JavaFX
        // // Start the JavaFX application by calling launch().
        // Application.launch(BasicFX.class, args);

        // // Program 1 : Dynamic Addition of RootNode
        // // Start the JavaFX application by calling launch().
        // Application.launch(DynamicAddFX.class, args);

        // // Program 2 : BLANK WINDOW
        // // Start the JavaFX application by calling launch().
        // Application.launch(BlankFX.class, args);

        // Program 3 : BASIC WINDOW WITH A BUTTON
        // Start the JavaFX application by calling launch().
        // statically on ButtonFX Class
        Application.launch(ButtonFX.class, args);

        // // Program 4 : ANIMATED TEXT APP
        // // Start the JavaFX application by calling launch().
        // Application.launch(TranslationFX.class, args);
    }

}
