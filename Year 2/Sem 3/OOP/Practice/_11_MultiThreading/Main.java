// main driver class
public class Main {

    // main driver method
    public static void main(String[] args) {
        System.out.println("\n");

        // // defining number of thread
        // int n = 8;

        // // looping over the threads
        // for (int i = 0; i < n; i++) {
        // TestThread threadObject = new TestThread();
        // threadObject.start();
        // }

        // creating runnable object
        InterfaceThread thread1 = new InterfaceThread("thread1");
        ClassThread thread2 = new ClassThread("--thread2--");

        try {
            thread1.thrd.join();
            System.out.println("Child #1 Joined");
            thread2.join();
            System.out.println("Child #2 Joined");
        } catch (InterruptedException e) {
            System.out.println("==Interrupted==");
        }

        // while (thread1.thrd.isAlive() && thread2.isAlive()) {
        // try {
        // Thread.sleep(500);
        // } catch (InterruptedException e) {
        // System.out.println("==Interrupted==");
        // }
        // System.out.println("...");
        // }
    }
}