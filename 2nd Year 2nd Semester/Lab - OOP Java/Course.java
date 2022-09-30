import java.util.*;

class Instructor {
    String name;
    long phno;

    void setData(String n, long p) {
        name = n;
        phno = p;
    }

    void getData() {
        System.out.println("Name = " + name);
        System.out.println("Phone = " + phno);
    }
}

class Textbook {
    String name;
    String author;
    String publisher;

    void setData(String n, String a, String p) {
        name = n;
        author = a;
        publisher = p;
    }

    void getData() {
        System.out.println("Name = " + name);
        System.out.println("Author = " + author);
        System.out.println("Publisher = " + publisher);
    }
}

public class Course {
    String cname;
    Instructor i;
    Textbook t;

    void setData(String n, long p, String n2, String a, String p) {
        name = n;
        i.setData(n, p);
        t.setData(n2, a, p);
    }

    void getData(String n, long p, String n2, String a, String p) {
        name = n;
        i.getData();
        t.getData();
    }
}