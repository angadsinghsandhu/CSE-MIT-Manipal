class InterfaceThread implements Runnable {
    // variable
    Thread thrd;

    // constructor
    InterfaceThread(String name) {
        thrd = new Thread(this, name); // naming the thread when it is created
        thrd.start(); // executing the thread
    }

    // thread entry-point
    public void run() {

        // printing name
        System.out.println("==" + thrd.getName() + " Running==");

        // error-handling
        try {
            // running loop
            for (int i = 0; i < 10; i++) {
                Thread.sleep(400);
                System.out.println("==" + thrd.getName() + " output : " + i + "==");
            }
        } catch (InterruptedException exe) {
            // printing interrupt exception
            System.out.println("==" + thrd.getName() + " Interrupted==");
        }

        // printing end of Thread
        System.out.println("==" + thrd.getName() + " Terminating==");
    }

}
