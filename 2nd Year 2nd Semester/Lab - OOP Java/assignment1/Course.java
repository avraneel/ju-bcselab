import java.util.*;

class Instructor {
	String name;
	int phno;
	
	Instructor(String name, int phno) {
		this.name = name;
		this.phno = phno;
	}
	
	void getdata() {
		System.out.println("Name: " + name);
		System.out.println("Phone: " + phno);
	}
}

class Textbook {
	String title;
	String author;
	String publisher;
	
	Textbook(String title, String author, String publisher) {
		this.title = title;
		this.author = author;
		this.publisher = publisher;
	}
	
	void getdata() {
		System.out.println("Title: " + title);
		System.out.println("Author: " + author);
		System.out.println("Publisher: " + publisher);
	}
}

public class Course {
	String cname;
	Instructor ins;
	Textbook b;
	
	Course(String cname, String name, int phno, String title, String author, String publisher) {
		this.cname = cname;
		ins = new Instructor(name, phno);
		b = new Textbook(title, author, publisher);
	}
	
	void getdata() {
		System.out.println("Course name: " + cname);
		System.out.println("Instructor details: ");
		ins.getdata();
		System.out.println("Textbook details: ");
		b.getdata();
	}
	
	public static void main(String args[]) {
		String cn = "", n = "";
		String t = "", a = "", pub = "";
		int ph;
		Course c;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter course name: ");
		cn = sc.nextLine();
		System.out.println("Enter instructor name & phone: ");
		n = sc.nextLine();
		ph = Integer.parseInt(sc.nextLine());
		System.out.println("Enter textbook title: ");
		t = sc.nextLine();
		System.out.println("Enter author & publisher: ");
		a = sc.nextLine();
		pub = sc.nextLine();
		c = new Course(cn, n, ph, t, a, pub);
		c.getdata();
	}
}
