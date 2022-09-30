package person;

import java.util.*;

class Person
{
	String name;
	String address;
	long phno;
	String email;
	
	void set()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter name: ");
		name = sc.nextLine();	
		System.out.println("Enter address. Use , to separate components. End with . : ");
		address = sc.nextLine();	
		System.out.println("Enter phno: ");
		phno = Long.parseLong(sc.nextLine());	
		System.out.println("Enter email: ");
		email = sc.nextLine();	
	}
			
	
	void disp()
	{
		System.out.println("Name: " + name);
		System.out.println("Address: " + address);
		System.out.println("Phone: "+ phno);
		System.out.println("Email: "+ email);
	}
	
	void changeaddress()
	{
		int ch;
		String wd;
		StringTokenizer st = new StringTokenizer(address, ",.");
		Scanner sc = new Scanner(System.in);
		String s1 = st.nextToken();
		String s2 = st.nextToken();
		String s3 = st.nextToken();
		String s4 = st.nextToken();
		String s5 = st.nextToken();
		System.out.println("What do you want to change?\n1. Premise\n2. Street\n3. City\n4. Pin\n5. State");
		ch = Integer.parseInt(sc.nextLine());
		System.out.println("Enter new String: ");
		wd = sc.nextLine();		
		switch(ch)
		{
			case 1: s1 = wd; 
				break;
			case 2: s2 = wd; 
				break;
			case 3: s3 = wd; 
				break;
			case 4: s4 = wd; 
				break;
			case 5: s5 = wd; 
				break;
			default: break;
		}
		address = s1 + " ," + s2 + " ," + s3 + " ," + s4 + " ," + s5 + ".";
		System.out.println("New Address:\n" + address);
	}
}

class Student extends Person
{
	int roll;
	String course;
	
	void disp()	
	{
		super.disp();
		System.out.println("Roll: " + roll);
		System.out.println("Course: " + course);
	}
	
	void set()
	{
		super.set();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter roll: ");
		roll = Integer.parseInt(sc.nextLine());	
		System.out.println("Enter course: ");
		course = sc.nextLine();	
	}

    public void setScore(double s) {
    }
}

class Faculty extends Person
{
	long id;
	String department;
	String specialization;
	
	void disp()	
	{
		super.disp();
		System.out.println("Employee Id: " + id);
		System.out.println("Department: " + department);
		System.out.println("Specialization: " + specialization);
	}
	
	void set()
	{
		super.set();	
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter id: ");
		id = Long.parseLong(sc.nextLine());	
		System.out.println("Enter department: ");
		department = sc.nextLine();	
		System.out.println("Enter specialization: ");
		specialization = sc.nextLine();	
	}
}

public class PersonHandler 
{
	public static void main(String[] args) 
	{
		char c; int ch;
		Scanner sc = new Scanner(System.in);
		Student s = null;
		Faculty f = null;	
		System.out.println("Enter f if Faculty. Any other key for Student.");
		c = sc.next().charAt(0);
		if(c == 'f')
		{
			f = new Faculty();
			f.set();
		}
		else
		{	
		 	s = new Student();
		 	s.set();
		}
		while(true)
		{
			System.out.println("Enter:\n1 to display details\n2 to set details again\n3 to change address partially\n0 to exit");
			ch = sc.nextInt();
			if(ch == 0)
				System.exit(0);
			switch(ch)
			{
				case 1: if(c == 'f')
							f.disp();
						else
							s.disp();
						break;
				case 2: if(c == 'f')
							f.set();
						else
							s.set();
						break;
				case 3: if(c == 'f')
							f.changeaddress();
						else
							s.changeaddress();
						break;
				default: System.out.println("Invalid input.");
			}
		}
	}
}
	
	
		
		
		
		
		
		
