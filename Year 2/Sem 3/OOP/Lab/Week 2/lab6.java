// package Year 2.Sem 3.OOP.Lab.Week 2;

public class lab6 {

    public static void main(String[] args) {
        
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

class Person{
    private String name;
    private Time dob;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Time getDob() {
        return dob;
    }

    public void setDob(Time dob) {
        this.dob = dob;
    }
}

class CollegeGraduate extends Person {
    private int gpa;
    private int graduateYear;
}
