package customer;

import java.util.*;

class Customer 
{
	long id;
	String name;
	double curamt;
	long phno;
	
	Customer(long id, String name, double curamt, long phno)
	{
		this.id = id;
		this.name = name;
		this.curamt = curamt;
		this.phno = phno;
	}	
}

class NormalCustomer extends Customer
{
	static final double credlim = 2000;
	
	NormalCustomer(long id, String name, double curamt, long phno)
	{
		super(id, name, curamt, phno);
	}
	
	void askLoan(double a) 
	{
		double s = curamt + credlim;
		if(a > s)
			System.out.println("Cannot apply for loan. Credit limit exceeded.");
		else
		{ 
			System.out.println("Loan application successful.");
			curamt += a;
		}
	}
	
	void disp()
	{
		System.out.println("Your credit limit is: "+ credlim);
		System.out.println("Your current loan amt is: "+ curamt);
		System.out.println("Maximum amount of loan you can seek: "+ (credlim+curamt));
	}		
}

class PrivilegedCustomer extends Customer
{
	static final double credlim = 5000;
	
	PrivilegedCustomer(long id, String name, double curamt, long phno) 
	{
			super(id, name, curamt, phno);
	}
	
	void askLoan(double a) 
	{
		double s = curamt + credlim;
		if(a > s)
			System.out.println("Cannot apply for loan. Credit limit exceeded.");
		else
		{ 
			System.out.println("Loan application successful.");
			curamt += a;
		}
	}
	
	void disp()
	{
		System.out.println("Your credit limit is: "+ credlim);
		System.out.println("Your current loan amt is: "+ curamt);
		System.out.println("Maximum amount of loan you can seek: "+ (credlim+curamt));
	}		
	
}

public class CustomerHandler
{
	public static void main(String[] args) {
		PrivilegedCustomer obp = null;
		NormalCustomer obc = null;
		char c; int ch; double ask; long id, phno; double curamt; String name;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter id: ");
		id = Long.parseLong(sc.nextLine());
		System.out.println("Enter name: ");
		name = sc.nextLine();
		System.out.println("Enter current loan amt: ");
		curamt = Double.parseDouble(sc.nextLine());
		System.out.println("Enter phno: ");
		phno = Long.parseLong(sc.nextLine());
		System.out.println("Enter p if priviledged. Any other key for normal customer.");
		c = sc.next().charAt(0);
		if(c == 'p')
			obp = new PrivilegedCustomer(id, name, curamt, phno);
		else
		 	obc = new NormalCustomer(id, name, curamt, phno);
		while(true)
		{
			System.out.println("Enter:\n1 to ask Loan\n2 to display details\n0 to exit");
			ch = sc.nextInt();
			if(ch == 0)
				System.exit(0);
			switch(ch)
			{
				case 1: System.out.println("Enter amount you want to apply for: ");
					ask = sc.nextDouble();
					if(c == 'p')
						obp.askLoan(ask);
					else
						obc.askLoan(ask);
					break;
				case 2: if(c == 'p')
						obp.disp();
					else
						obc.disp();
					break;
				default: System.out.println("Invalid input");
			}
		}
	}
}
		
			 

