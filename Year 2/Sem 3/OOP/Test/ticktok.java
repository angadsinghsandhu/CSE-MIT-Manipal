class TickTok {
    String state;
    
    synchronized void tick(boolean running){
        if(!running){
            state = "ticked";
            notify();
            return;
        }
        
        System.out.println("Tick ");
        
        state = "ticked";
        
        notify();
        
        try{
            while(!state.equals("tocked")){
                wait();
            }
        } catch (InterruptedException ie){
            System.out.println("Thread Interrupted");
        }
    }
    
    synchronized void tock(boolean running){
        if(!running){
            state = "tocked";
            notify();
            return;
        }
        
        System.out.println("Tock ");
        
        state = "tocked";
        
        notify();
        
        try {
            while(!state.equals("ticked")){
                wait();
            }
        } catch(InterruptedException ie) {
            System.out.println("Thread Interrupted");
        }
    }
}

class MyThread implements Runnable {
    Thread thrd;
    TickTok tt;
    
    MyThread(String name, TickTok tt){
        thrd = new Thread(this, name);
        this.tt = tt;
        thrd.start();
    }
    
    public void run() {
        if(thrd.getName().compareTo("Tick") == 0){
            for(int i = 0; i<5; i++)
                tt.tick(true);
            tt.tick(false);
            
        } else {
            for(int i = 0; i<5; i++)
                tt.tock(true);
            tt.tock(false);
        }
    }
}

class ticktok{
    
    public static void main(String args[]){
        TickTok tt = new TickTok();
        MyThread t1 = new MyThread("Tick", tt);
        MyThread t2 = new MyThread("Tock", tt);
        
        try{
            t1.thrd.join();
            t2.thrd.join();
        } catch (InterruptedException ie) {
            System.out.println("Thread Interruted");
        }
    }
    
}















