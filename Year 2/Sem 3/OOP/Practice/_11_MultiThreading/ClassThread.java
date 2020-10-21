public class ClassThread extends Thread {

    // constructor that inherits from thread
    ClassThread(String name) {
        super(name); // naming the thread when it is created
        start(); // executing the thread
    }

    // thread entry-point
    public void run() {

        // printing name
        System.out.println("==" + getName() + " Running==");

        // error-handling
        try {
            // running loop
            for (int i = 0; i < 10; i++) {
                Thread.sleep(400);
                System.out.println("==" + getName() + " output : " + i + "==");
            }
        } catch (InterruptedException exe) {
            // printing interrupt exception
            System.out.println("==" + getName() + " Interrupted==");
        }

        // printing end of Thread
        System.out.println("==" + getName() + " Terminating==");
    }

}
