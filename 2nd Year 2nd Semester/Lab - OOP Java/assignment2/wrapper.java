import java.util.*;

class wrapper 
{
	public static void main(String args[]) 
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a number: ");
		int i = Integer.parseInt(sc.nextLine());
		Integer in = i;		// Basic to object
		int k = in.intValue();		//object to basic
		System.out.println("intValue() result: " + k);
		System.out.println("Enter a number: ");
		String x = sc.next();
		int j = Integer.parseInt(x);		//basic to string
		System.out.println("parseint result: "+ j);
		Integer in2 = Integer.parseInt("56");	// string to object
		System.out.println(in2);
		String s = in.toString();		// object to string
		System.out.println("In string: " + s);
	}
}
		
		
		
		
		
		
		
		
