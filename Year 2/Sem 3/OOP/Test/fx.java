import java.awt.TextField;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.layout.*;
import javafx.stage.Stage;

import javafx.scene.control.*;
import javafx.event.*;

public class Main {
    System.out.println("Staring JavaFx Application");
    Application.launch(Fx.class, args);
}

class Fx extends Application {
    int data;
    String username;
    String password;

    public void init(){

    }

    // // PART-0
    // public void start(Stage myStage){
    //     System.out.println("Inside the start() method");

    //     myStage.setTitle("FX APP");

    //     FlowPane root = new FlowPane();

    //     Scene myScene = new Scene(root, 300, 300);

    //     myStage.setScene(myScene);

    //     myStage.show();
    // }

    // PART-1
    public void start(Stage myStage) throws Exception{
        System.out.println("Inside the start() application");

        myStage.setTitle("This is the First JavaFx Application");
        myStage.setWidth(500);
        myStage.setHeight(200);

        Label myLabel1 = new Label("Welcome to JavaFx programming");
        mylabel1.setTextFill(Color.web("#ff00ff", 0.8));

        TextField myTextField = new TextField("Input Number");
        myTextField.setOnAction(new EventHandler<ActionEvent>(){
            @Override
            public void handle(ActionEvent event){
                data = Integer.parseInt(myTextField.getText());
                for(int i=1; i<=10; i++)
                    System.out.println(String.format("%d x %d = %d", data, i, data*i));
            }
        });

        Label myLabe2 = new Label("Enter Number");
        myLabe2.setLabelFor(myTextField);

        FlowPane root = new FlowPane();
        root.setVgap(8);
        root.setHgap(4);

        root.getChildren().add(myLabe1);
        root.getChildren().add(myLabe2);
        root.getChildren().add(myTextField);

        Scene myScene = new Scene(root, 500, 200);

        myStage.setScene(myScene);

        myStage.show();
    }

    // PART-2
    public void start(Stage myStage) throws Exception {
        myStage.setTitle("");

        GridPane root = new GridPane();

        Label nameLabel = new Label("User Name");
        TextField nameField = new TextField();
        nameLabel.setLabelFoe(nameField);
        
        // action on textfies
        nameField.setOnAction(new EventHandler<ActionEvent>(){
            @Override
            public void handle(ActionEvent event){
                username = nameField.getText();
            }
        });
        
        
        Label passLabel = new Label("Password");        
        PasswordField passField = new PasswordField();
        passLabel.setLabelFoe(passField);
        
        passField.setOnAction(new EventHandle<ActionEvent>(){
            @Override
            public void handle(ActionEvent event){
                password = passField.getText();
            }
        });

        Button btn = new Button();

        Scene myScene = new Scene(root, 300, 300);

        myStage.addScene(myScene);

        myStage.show();
    }

    public void stop(){

    }
}

