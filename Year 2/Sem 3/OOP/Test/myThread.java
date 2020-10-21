public class myThread extends Thread {

    // constructor
    myThread(String name) {
        super(name); // naming the thread when it is created
        start();
    }
}
