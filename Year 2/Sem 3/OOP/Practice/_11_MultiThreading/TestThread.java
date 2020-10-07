// thread class
public class TestThread extends Thread {

    // run method
    public void run() {
        try {
            // display that the thread is running
            System.out.println("Thread is Running....\n");
            System.out.println("Thread id : " + Thread.currentThread().getId() + "\n");
            System.out.println("Thread name : " + Thread.currentThread().getName() + "\n");
            System.out.println("Thread priority : " + Thread.currentThread().getPriority() + "\n\n\n");
            // gives out jumbled results

        } catch (Exception e) {
            // throwing an exception
            System.out.println("Error Occoured...\n\n\n");
        }
    }
}