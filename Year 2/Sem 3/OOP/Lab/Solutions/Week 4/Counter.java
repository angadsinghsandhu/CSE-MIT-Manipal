import java.util.Scanner;
import java.lang.Math;

public class Counter
{
	static int counter=0;

	private static void updateCounter()
	{
		counter=counter+1;
	}

	public static void showCount()
	{
		System.out.println("Counter is at: "+counter);
	}
	
	public Counter()
	{
		updateCounter();
	}

	public static void main(String[] arg)
	{
		Counter a=new Counter();
		Counter b=new Counter();
		Counter c=new Counter();
		showCount();
	}
}
