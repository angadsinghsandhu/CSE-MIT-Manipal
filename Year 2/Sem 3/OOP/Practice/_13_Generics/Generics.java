// declaring package
package _13_Generics;

// imports
import java.util.ArrayList;

// generics class
public class Generics {

    // function that adds string and integer to type-safe list
    public void safeAdd(Integer num) {

        // type safe List declaration
        ArrayList<Integer> values = new ArrayList<Integer>();

        // inserting value
        values.add(num);

        // printing out type and message
        System.out.println(String.format("the type of this list is : %s", values.get(0).getClass().getSimpleName()));
        System.out.println(String.format("Integer : %d, has been sucessfully added", num));

    }

    // function that adds string and integer to type-unsafe list
    public void unsafeAdd(Object str) {

        // unsafe type def List declaration
        ArrayList arr = new ArrayList();

        // inserting value
        arr.add(str);

        // printing out type and message
        System.out.println(String.format("the type of this list is : %s", arr.get(0).getClass().getSimpleName()));
        System.out.println(String.format("String : %s, has been sucessfully added", str));

    }

}