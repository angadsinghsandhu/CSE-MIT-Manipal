//'main' method must be in a class 'Rextester'.
//openjdk version '11.0.5' 

import java.util.*;
import java.lang.*;

class Counter extends Thread {
    // variable
    private static int count;

    // constructor
    Counter(String name) {
        super(name); // naming the thread when it is created
        Counter.count = 0; // initializing integer as 0
        start();
    }

    // empty thread entry point
    public void run() {

    }

    // helper methods
    synchronized void increment() {
        // System.out.println("==Increment Executed " + this.count + "==");
        if (Counter.count >= 3) {

            // (wait for count to reduce)
            System.out.println("wait for count to reduce");

            // waiting
            try {
                // notify decrement
                notifyAll();
                wait();
            } catch (InterruptedException e) {
                // printing interrupt exception
                System.out.println("==" + getName() + " Interrupted==");
            }

        } else {

            // incrementing counter
            Counter.count++;
            System.out.println("increment() function has occured, count : " + this.count);

            // sleeping for 500ms
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                // printing interrupt exception
                System.out.println("==" + getName() + " Interrupted==");
            }
        }
    }

    synchronized void decrement() {
        if (Counter.count <= 0) {

            // (wait for count to increase)
            System.out.println("wait for count to increase");

            // waiting
            try {
                // notify increment
                notifyAll();
                wait();
            } catch (InterruptedException e) {
                // printing interrupt exception
                System.out.println("==" + getName() + " Interrupted==");
            }

        } else {

            // decrementing
            Counter.count--;
            System.out.println("decrement() function has occured, count : " + this.count);

            // sleeping
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                // printing interrupt exception
                System.out.println("==" + getName() + " Interrupted==");
            }
        }
    }

    public static int getCount() {
        return count;
    }
}

public class Test {

    // main driver method
    public static void main(String[] args) {
        System.out.println("\n");

        // creating threads
        Counter c = new Counter("c");

        Thread t1 = new Thread(new Runnable() {
            public void run() {
                for (int i = 0; i < 1000; i++)
                    c.increment();
            }
        });

        Thread t2 = new Thread(new Runnable() {
            public void run() {
                for (int i = 0; i < 1000; i++)
                    c.decrement();
            }
        });

        t1.start();
        t2.start();

        // creating threads
        Counter incrementThread = new Counter("incrementThread");
        Counter decrementThread = new Counter("decrementThread");

        // incrementing and decrementing
        incrementThread.increment();
        incrementThread.increment();
        incrementThread.increment();
        incrementThread.increment();

        decrementThread.decrement();
        decrementThread.decrement();
        decrementThread.decrement();
        decrementThread.decrement();

        // System.out.println("Count = " + Counter.getCount());
    }

}