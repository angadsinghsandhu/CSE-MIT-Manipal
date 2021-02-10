import java.util.Scanner;
import java.lang.Math;

public class Time
{
	int hours, minutes, seconds;
	public Time(int h, int m, int s)
	{
		this.hours=h;
		this.minutes=m;
		this.seconds=s;
	}

	public static Time getTime()
	{
		Scanner sc=new Scanner(System.in);
		Time a=new Time(0, 0, 0);
		System.out.print("Enter Hours: ");
		a.hours=sc.nextInt();
		System.out.print("Enter Minutes: ");
		a.minutes=sc.nextInt();	
		System.out.print("Enter Seconds: ");
		a.seconds=sc.nextInt();

		//Handling cases when seconds or minutes>60
		a.minutes+=a.seconds/60;
		a.seconds=a.seconds%60;
		a.hours+=a.minutes/60;
		a.minutes=a.minutes%60;

		return a;
	}
	
	public void display()
	{
		System.out.println("The time is: "+this.hours+":"+this.minutes+":"+this.seconds);
	}

	public Time add(Time a)
	{
		Time c=new Time(0, 0, 0);
		c.hours=this.hours+a.hours;
		c.minutes=this.minutes+a.minutes;
		c.seconds=this.seconds+a.seconds;

		return c;
	}

	public Time subtract(Time a)
	{
		Time c=new Time(0, 0, 0);
		c.hours=this.hours-a.hours;
		c.minutes=this.minutes-a.minutes;
		c.seconds=this.seconds-a.seconds;

		return c;
	}

	public int isGreaterThan(Time a)
	{
		if(this.hours*24+this.minutes*60+this.seconds>a.hours*24+a.minutes*60+a.seconds)
			return 1;
		else if(this.hours*24+this.minutes*60+this.seconds==a.hours*24+a.minutes*60+a.seconds)
			return 0;
		else
			return -1;
	}
	
	public static void main(String arg[])
	{
		//initialise
		Time obj1=getTime();
		Time obj2=getTime();

		//display
		obj1.display();
		obj2.display();
		
		//add and display
		System.out.print("Added: ");
		(obj1.add(obj2)).display();

		//subtract and display
		System.out.print("Subtracted: ");
		(obj1.subtract(obj2)).display();

		//compare and tell
		if(obj1.isGreaterThan(obj2)==1)
			System.out.println("Time1 is greater");
		if(obj1.isGreaterThan(obj2)==0)
			System.out.println("They are equal");
		if(obj1.isGreaterThan(obj2)==-1)
			System.out.println("Time2 is greater");
	}
}
