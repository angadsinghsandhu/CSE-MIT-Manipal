import java.util.Scanner;

import javax.management.QueryExp;

class MyThread extends Thread{
    public void run(){
        try{
            System.out.println("Thread : " + Thread.currentThread().getId() + " is running...");
        } catch (Exception e) {
            System.out.println("Exception Caught");
        }
    }
}

class YourThread implements Runnable{
    public void run(){
        try{
            System.out.println("Thread : " + Thread.currentThread().getId() + " is running...");
        } catch (Exception e) {
            System.out.println("Exception Caught");
        }
    }
}


class Table extends Thread{
    private Thread t;
    private int num;
    
    public Table(){
        this.num = 1;
        System.out.println("");
    }

    public Table(int num){
        this.num = num;
        System.out.println("");
    }

    public void printTable(){
        System.out.println(String.format("Printing Table of : %d", this.num));
        System.out.println("___________________");
        for(int i = 1; i<=10; i++)
            System.out.println(String.format("| %d x %d | %d |", this.num, i, this.num*i));
        System.out.println("__________________");
    }

    public void run(){
        System.out.println(String.format("Executing Thread : %d", Thread.currentThread().getName()));
        this.printTable();        
    }

    public void start(){
        System.out.println(String.format("Starting String For : %d", this.num));
        if(t==null)
            t = new Thread(this, String.format("Thread_%d", this.num));
        t.start();
    }
}

class Matrix {
    private int arr [][];

    Matrix(int m, int n){
        this.arr = new int[m][n];
    }

    Matrix(){
        this.arr = new int[0][0];
    }

    public int[] getRow(int i){
        return arr[i];
    } 

    void input(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Matrix\n");
            for(int i=0; i<arr.length; i++)
                for(int j=0; j<arr[0].length; j++)
                    arr[i][j] = sc.nextInt();
        sc.close();
    }
}

class RowSum implements Runnable {
    private int row[];
    private int sum;

    RowSum(int a[]){
        this.row = a;
        this.sum = 0;
    }

    public int getRowSum() {
        return sum;
    }

    public void run(){
        System.out.println("Implementing List...");
        for(int i=0; i<row.length; i++)
            sum += row[i];
    }
}

class Q {
    int n;
    boolean valueSet = false;

    synchronized void get(){
        while(!valueSet){
            try{
                wait();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        System.out.println("Got : " + n);
        valueSet = false;
        notify();
    }

    synchronized void put(int n){
        while(valueSet){
            try {
                wait();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        this.n = n;
        System.out.println("Put : " + n);
        valueSet = true;
        notify();
    }
}

class Producer implements Runnable {
    Q q;

    Producer(Q q){
        this.q = q;
        new Thread(this, "Producer").start();
    }

    public void run(){
        int i=0;
        
        while(i<10){
            q.put(i++);
        }
    }
}

class Consumer implements Runnable {
    Q q;

    Consumer(Q q){
        this.q = q;
        new Thread(this, "Consumer").start();
    }

    public void run(){
        
        while(true){
            q.get();
        }
    }
}

public class Main {

    public static void main(String args[]){
        // // PART-1
        // int n = 8;

        // for(int i=0; i<n; i++){
        //     MyThread myThread = new MyThread();
        //     myThread.start();

        // // PART-2
        // Table t1 = new Table(5);
        // t1.start();

        // try {
        //     t1.join();
        // } catch (Exception e) {
        //     e.printStackTrace();
        // }

        // Table t2 = new Table(7);
        // t2.start();

        // // PART-3
        // System.out.println("Enter Dimentions of the Matrix");
        // Scanner sc = new Scanner(System.in);
        // System.out.print("Number of Rows : ");
        // int m = sc.nextInt();
        // System.out.print("Number of Columns : ");
        // int n = sc.nextInt();
        // Matrix mat = new Matrix(m, n);
        // mat.input();

        // // array of threads
        // Thread threads[] = new Thread[m];
        // RowSum rowsum[] = new RowSum[m];
    
        // for(int i=0; i<m; i++){
        //     rowsum[i] = new RowSum(mat.getRow(i));
        //     threads[i] = new Thread(rowsum[i]);
        //     threads[i].start();
        // }

        // int sum=0;

        // try{
        //     for(int i=0; i<m; i++){
        //         threads[i].join();
        //         sum += rowsum[i].getRowSum();
        //     }
        // } catch (Exception e) {
        //     e.printStackTrace();
        // }
            
        // System.out.println(String.format("The Sum is : %d", sum));

        // PART-4
        Q q = new Q();
        new Producer(q);
        new Consumer(q);

    }
}
    
