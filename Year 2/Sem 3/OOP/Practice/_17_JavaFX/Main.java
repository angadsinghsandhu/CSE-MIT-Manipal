// declaring package
package _17_JavaFX;

// A JavaFX application skeleton.
import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;

// main driver class
public class Main extends Application {

    // main driver method
    public static void main(String[] args) {
        System.out.println("\n");

        System.out.println("Launching JavaFX application.");

        // Start the JavaFX application by calling launch().
        launch(args);
    }

    // Override the init() method.
    public void init() {
        System.out.println("Inside the init() method.");
    }

    // Override the start() method.
    public void start(Stage myStage) {
        System.out.println("Inside the start() method.");
        // Give the stage a title.
        myStage.setTitle("JavaFX Skeleton.");
        // Create a root node. In this case, a flow layout
        // is used, but several alternatives exist.
        FlowPane rootNode = new FlowPane();
        // Create a scene.
        Scene myScene = new Scene(rootNode, 300, 200);
        // Set the scene on the stage.
        myStage.setScene(myScene);
        // Show the stage and its scene.
        myStage.show();
    }

    // Override the stop() method.
    public void stop() {
        System.out.println("Inside the stop() method.");

    }
}