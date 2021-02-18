// package Year 2.Sem 3.OOP.Lab.Week 1;

public class lab4 {
    public static void main(String[] args) {
        
        Counter count0 = new Counter();
        Counter count1 = new Counter();
        Counter count2 = new Counter();
        Counter count3 = new Counter();
        count0.none();
        count1.display();
        count2.none();
        count3.none();
    }
}

class Counter {
    static int counter = 0;

    Counter() {
        counter++;
    }

    void display() {
        System.out.println(String.format("the number of objects of Counter class are : %d", counter));
    }

    void none(){

    }
}
