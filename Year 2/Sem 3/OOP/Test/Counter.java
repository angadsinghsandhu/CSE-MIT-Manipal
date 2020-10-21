public class Counter extends Thread {
    // variable
    private static int count;

    // constructor
    Counter(String name) {
        super(name); // naming the thread when it is created
        this.count = 0; // initializing integer as 0
        start();
    }

    // empty thread entry point
    public void run() {

    }

    // helper methods
    synchronized void increment() {
        if (this.count >= 3) {

            // (wait for count to reduce)
            System.out.println("wait for count to reduce");

            // waiting
            try {
                wait();
            } catch (InterruptedException e) {
                // printing interrupt exception
                System.out.println("==" + getName() + " Interrupted==");
            }

        } else {

            // incrementing counter
            this.count++;
            System.out.println("increment() function has occured, count : " + this.count);

            // sleeping for 500ms
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                // printing interrupt exception
                System.out.println("==" + getName() + " Interrupted==");
            }

            // notify decrement thread
            notify();

        }
    }

    synchronized void decrement() {
        if (this.count <= 0) {

            // (wait for count to increase)
            System.out.println("wait for count to increase");

            // waiting
            try {
                wait();
            } catch (InterruptedException e) {
                // printing interrupt exception
                System.out.println("==" + getName() + " Interrupted==");
            }

        } else {

            // decrementing
            this.count--;
            System.out.println("decrement() function has occured, count : " + this.count);

            // sleeping
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                // printing interrupt exception
                System.out.println("==" + getName() + " Interrupted==");
            }

            // notify increment
            notify();
        }
    }
}
