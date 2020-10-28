// Creating Generic Methods
public class ElementContainer<E> {

    public static <E> void printArray(E[] elements) {
        for (E element : elements) {
            System.out.print(element);
            System.out.print(" ");
        }
        System.out.println();
    }

}
