// declaring package
package _13_Generics;

// imports
import java.util.List;

// The unbounded wildcard type represents the list of an unknown type
public class UnboundWildcard {
    // Any class type
    public static void displayWeird(List<?> list) {
        System.out.println("\n");
        // looping through array of any type
        for (Object o : list) {
            System.out.print(o);
            System.out.println(" in unbound wildcard... ");
        }
        // System.out.println("\n");
    }

}
