import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Locale;

// package Year 2.Sem 3.OOP.Lab.Week 2;

public class lab5 {

    public static void main(String[] args) {

    }

}

class Student {
    static int counter;
    int reg_no;
    String name;
    GregorianCalendar gc;
    short sem;
    float gpa, cgpa;

    // Default Constructor
    Student() {
        this.name = "";
        this.gc = new GregorianCalendar(new Locale("en", "IN"));
        this.reg_no = (GregorianCalendar.YEAR).substring(2) + String.valueOf(counter);
        this.sem = 0;
        this.gpa = 0;
        this.cgpa = 0;
    }

    // Overwritten Constructor
    Student(int reg_no, String name, GregorianCalendar gc, short sem, float gpa, float cgpa){
        this.reg_no = reg_no;
        this.name = name;
        this.gc = gc;
        this.sem = sem;
        this.gpa = gpa;
        this.cgpa = cgpa;
    }

    void display(Student stu){
        System.out.println("the Student details are : ");
        System.out.println(String.format("the name of the Student : %s", stu.getName()));
        System.out.println(String.format("the Registration Number of the Student : %d", stu.getReg_no()));
        System.out.println(String.format("the Date of Joining of the Student : %s", stu.getGc()));
        System.out.println(String.format("the Semester of the Student : %s", stu.getSem()));
        System.out.println(String.format("the GPA of the Student : %s", stu.getGpa()));
        System.out.println(String.format("the CGPA of the Student : %s", stu.getCgpa()));
    }

    void createArray(){
        Student[] stuArray = new Student[5];

        for (int i = 0; i < stuArray.length; i++) {
            stuArray[i].setName();
            stuArray[i].setReg_no();
            stuArray[i].setGc();
            stuArray[i].setSem();
            stuArray[i].setGpa();
            stuArray[i].setCgpa();
        }
    }

    public String getName() {
        return name;
    }

    public float getCgpa() {
        return cgpa;
    }

    public static int getCounter() {
        return counter;
    }

    public GregorianCalendar getGc() {
        return gc;
    }

    public float getGpa() {
        return gpa;
    }

    public int getReg_no() {
        return reg_no;
    }

    public short getSem() {
        return sem;
    }

    public void setCgpa(float cgpa) {
        this.cgpa = cgpa;
    }

    public static void setCounter(int counter) {
        Student.counter = counter;
    }
    public void setGc(GregorianCalendar gc) {
        this.gc = gc;
    }

    public void setGpa(float gpa) {
        this.gpa = gpa;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setReg_no(int reg_no) {
        this.reg_no = reg_no;
    }

    public void setSem(short sem) {
        this.sem = sem;
    }
}
