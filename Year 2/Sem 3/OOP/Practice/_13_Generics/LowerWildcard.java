// declaring package
package _13_Generics;

// imports
import java.util.List;

// Here `?` is a wildcard character which is extended by a class (i.e. super)
public class LowerWildcard {
    // A class type that is extended by Integer
    public static void displayWeird(List<? super Integer> list) {
        System.out.println("\n");
        // looping through array of any type
        for (Object o : list) {
            System.out.print(o);
            System.out.println(" in lowerbound wildcard... ");
        }
        System.out.println("\n");
    }

}
