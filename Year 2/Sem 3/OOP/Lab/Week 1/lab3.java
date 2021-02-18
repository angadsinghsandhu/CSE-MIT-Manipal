// package Year 2.Sem 3.OOP.Lab.Week 1;
import java.util.Scanner;

public class lab3 {

    public static void main(String[] args) {
        

        Scanner sc = new Scanner(System.in);

        Complex com = new Complex(2, 2);
        Time time = new Time(12, 12, 12);

        com.display();
        time.display();

        sc.close();
    }
    
}

class Complex{
    // variables
    int re, im;

    // default constructor
    Complex(){
        this.re = this.im = 0;
    }

    // hotwiring constructor
    Complex(int re, int im){
        this.re = re;
        this.im = im;
    }

    void display() {
        System.out.println(String.format("complex number : %d+i%d", this.re, this.im));
    }

    Complex add(Complex num){
        Complex added = new Complex((this.re + num.getRe()), (this.im + num.getIm()));
        return added;
    }

    Complex sub(Complex num){
        Complex subed = new Complex(Math.abs(this.re - num.getRe()), Math.abs(this.im - num.getIm()));
        return subed;
    }

    public int getIm() {
        return this.im;
    }

    public int getRe() {
        return this.re;
    }
}

class Time{
    int hrs, mins, secs;

    // default constructor
    Time(){
        this.hrs = this.mins = this.secs = 00;
    }

    // hotwiring constructor
    Time(int hr, int min, int sec){
        if(sec>60){
            sec %= 60;
            min += sec/60;
        }

        if(min>60){
            min %= 60;
            hr += min/60;
        }

        if(hr>24){
            hr %= 24;
        }

        this.hrs = hr;
        this.mins = min;
        this.secs = sec;
    }

    void display(){
        System.out.println(String.format("time = %02d:%02d:%02d", this.hrs, this.mins, this.secs));
    }

    Time add(Time tm){
        Time t = new Time(this.hrs + tm.getHrs(), this.hrs + tm.getMins(), this.secs + tm.getSecs());
        return t;
    }

    Time sub(Time tm){
        Time t = new Time(this.hrs - tm.getHrs(), this.hrs - tm.getMins(), this.secs - tm.getSecs());
        return t;
    }

    public int getHrs() {
        return hrs;
    }

    public int getMins() {
        return mins;
    }

    public int getSecs() {
        return secs;
    }

}
