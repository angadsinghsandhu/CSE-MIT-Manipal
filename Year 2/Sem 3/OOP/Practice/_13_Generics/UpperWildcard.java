
// imports
import java.util.ArrayList;

// Here `?` is a wildcard character which extends a class
public class UpperWildcard {
    // A class type that extends Number
    public static void displayWeird(ArrayList<? extends Number> num) {
        System.out.println("\n");
        // looping through array of any type
        for (Object o : num) {
            System.out.print(o);
            System.out.println(" in upper bound wildcard... ");
        }
        System.out.println("\n");
    }

}
