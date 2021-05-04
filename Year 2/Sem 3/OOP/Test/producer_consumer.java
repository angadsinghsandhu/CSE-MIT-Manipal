class Q{
    int n;
    boolean value = false;
    
    int get(){
        while(!value){
            try{
                wait();
            } catch (InterruptedException ie){
                System.out.println("Thread is Interrupted");
            }
        }
        
        System.out.println("Got: " + n);
        value = false;
        notify();
        return n;
    }
    
    void set(int n){
        while(value){
            try {
                wait();
            } catch(InterruptedException ie) {
                System.out.println("Thread is Interrupted");
            }
        }
        
        this.n = n;
        value = true;
        System.out.println("Put: " + n);
        notify();
    }
}

class Producer extends Thread{
    Thread thrd;
    Q q;
    
    Producer(Q cls){
        super("Producer");
        q = cls;
        run();
    }
    
    public void start(){
        int i = 0;
        
        for(;;){
            synchronized (this.q){
                q.set(i++);
            }
        }
    }
} 

class Consumer extends Thread{
    Thread thrd;
    Q q;
    
    Consumer(Q cls){
        super("Consumer");
        q = cls;
        run();
    }
    
    public void start(){
        for(;;){
            synchronized(q){
                q.get();
            }
        }
    }
} 

public class producer_consumer {
    public static void main (String args[]){
        Q q = new Q();
        Producer t1 = new Producer(q);
        Consumer t2 = new Consumer(q);
    }
}