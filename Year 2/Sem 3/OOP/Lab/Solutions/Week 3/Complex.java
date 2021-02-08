import java.util.Scanner;
import java.lang.Math;

public class Complex
{
	int real, imaginary;
	public Complex(int re, int im)
	{
		this.real=re;
		this.imaginary=im;
	}

	public static Complex getComplex()
	{
		Complex a = new Complex(0, 0);
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
		Complex c = new Complex(0, 0);
		c.real=a.real+this.real;
		c.imaginary=a.imaginary+this.imaginary;
		return c;
	}

	public Complex subtract(Complex a)
	{
		Complex c = new Complex(0, 0);
		c.real=Math.abs(this.real-a.real);//Absolute value after subtratction
		c.imaginary=Math.abs(this.imaginary-a.imaginary);//Absoulte value after subtratction
		return c;
	}

	public static void main(String[] arg)
	{
		//Add
		Complex obj1 = getComplex();
		Complex obj2 = getComplex();

		//Display
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
