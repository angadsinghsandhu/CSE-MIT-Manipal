
// imports
import java.util.*;

class C<T> {
    T data;

    C(T t) {
        data = t;
    }
}

// main driver class
public class Main {
    /*
     * GENERICS
     * 
     * Java is a `type-safe` language, i.e. every object has to be type defined at
     * declaration.
     * 
     * Java Generic methods and generic classes enable programmers to specify, with
     * a single method declaration, a set of related methods, or with a single class
     * declaration, a set of related types, respectively.
     * 
     * Generics also provide compile-time type safety that allows programmers to
     * catch invalid types at compile time.
     */

    // main driver method
    public static void main(String[] args) {
        System.out.println("\n");

        // creating generics and scanner testing object
        Scanner sc = new Scanner(System.in);

        // first method
        genericsExample(sc);
        System.out.println("\n\n");

        // second method
        typeContainerExample(sc);
        System.out.println("\n\n");

        // close scanner
        sc.close();

    }

    public static void genericsExample(Scanner sc) {
        // creating generics object
        Generics g = new Generics();

        // getting variables
        System.out.print("Enter An Integer : ");
        int num = sc.nextInt();
        System.out.print("Enter A String : ");
        Object str = sc.next();

        // // close scanner
        // sc.close();

        // executing safeAdd()
        System.out.println("\nadding string and integer to type-safe list\n");
        g.safeAdd(num);

        // executing unsafeAdd()
        System.out.println("\nadding string and integer to type-unsafe list\n");
        g.unsafeAdd(str);
    }

    public static void typeContainerExample(Scanner sc) {
        // getting variables
        System.out.println("Enter A Type, Options are : [i, s, f]");
        System.out.print("Enter Type : ");
        String str = sc.next();

        // creating TypeContainer object
        if (str.equals("i")) {
            TypeContainer<Integer> t = new TypeContainer<Integer>();
            t.value = 0; // assigning value
            t.show(); // printing type of object defined
        } else if (str.equals("s")) {
            TypeContainer<String> t = new TypeContainer<String>();
            t.value = "string"; // assigning value
            t.show(); // printing type of object defined
        } else if (str.equals("f")) {
            TypeContainer<Float> t = new TypeContainer<Float>();
            t.value = (float) 0.9; // assigning value
            t.show(); // printing type of object defined
        } else {
            System.out.println(String.format("The value you entered : '%s', Didn't match any type, TRY AGAIN", str));
            return;
        }

        return;

    }
}