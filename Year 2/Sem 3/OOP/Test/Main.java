public class Main {

    // main driver method
    public static void main(String[] args) {
        System.out.println("\n");

        // creating threads
        Counter incrementThread = new Counter("incrementThread");
        Counter decrementThread = new Counter("decrementThread");

        // incrementing and decrementing
        incrementThread.increment();
        incrementThread.increment();
        incrementThread.increment();
        incrementThread.increment();
        decrementThread.decrement();
    }

}