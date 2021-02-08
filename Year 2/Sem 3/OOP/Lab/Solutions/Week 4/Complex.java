import java.util.Scanner;
import java.lang.Math;

public class Complex
{
	int real, imaginary;

	//Default cONSTRUCTOR
	public Complex()
	{
		System.out.println("Default constructor called");
		this.real=0;
		this.imaginary=0;
	}
	
	//Parameterised Constructor
	public Complex(int re, int im)
	{
		System.out.println("Parametrised constructor called");
		this.real=re;
		this.imaginary=im;
	}

	//Parameterised Constructor with Object as Parameter
	public Complex (Complex c)
	{
		System.out.println("Parametrised constructor called with Complex as parameter");
		this.real=c.real;
		this.imaginary=c.imaginary;
	}

	public static Complex getComplex()
	{
		Complex a = new Complex();
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter real part: ");
		a.real=sc.nextInt();
		System.out.print("Enter imaginary part: ");
		a.imaginary=sc.nextInt();

		return a;		
	}

	public void display()
	{
		System.out.println("Complex number: "+this.real+" + i("+this.imaginary+")");
	}

	public Complex add(Complex a)
	{
		Complex c = new Complex();//default constructor used
		c.real=a.real+this.real;
		c.imaginary=a.imaginary+this.imaginary;
		return c;
	}

	public Complex subtract(Complex a)
	{
		Complex c = new Complex(0, 0);//first parameterised constructor used
		c.real=this.real-a.real;
		c.imaginary=this.imaginary-a.imaginary;
		return c;
	}

	public static void main(String[] arg)
	{
		//Add
		Complex obj1 = getComplex();
		Complex obj2 = new Complex(getComplex());//giving Complex object as parameter for constructor

		//Display method
		obj1.display();
		obj2.display();

		//Add and display
		System.out.print("Sum: ");
		(obj1.add(obj2)).display();

		//Subtract and display
		System.out.print("Difference: ");
		(obj1.subtract(obj2)).display();
		
	}
}
