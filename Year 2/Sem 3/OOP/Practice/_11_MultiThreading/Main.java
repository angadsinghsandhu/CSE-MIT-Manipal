// main driver class
public class Main {

    // main driver method
    public static void main(String[] args) {
        System.out.println("\n");

        // defining number of thread
        int n = 8;

        // looping over the threads
        for (int i = 0; i < n; i++) {
            TestThread threadObject = new TestThread();
            threadObject.start();
        }
    }
}