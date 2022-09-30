import java.util.*;
import java.io.*;

class Student implements Serializable
{
    int roll;
    String name;
    double score;

    Student(int roll, String name, double score)
    {
        this.roll = roll;
        this.name = name;
        this.score = score;
    }

    public String toString()
    {
        return("Roll = " + roll + "\nName = " + name + "\nScore = " + score);
    }  
}

class StudentWrite                  //class to Read/Write Student objects
{
    String filename;

    void read()                                                                    //read Student objects from file
    {
        try
        {
            File f = new File(filename);
            FileInputStream fi = new FileInputStream(f);
            ObjectInputStream oi = new ObjectInputStream(fi);
            Student ob = (Student)(oi.readObject());
            System.out.println(ob);
            oi.close();
        }
        catch (IOException e)
        {
           System.out.println(e);

        }
        catch(ClassNotFoundException e)
        {
            System.out.println("Class not found");
        }
    }

    void write(Student o)                                                           //Take Student input from user and loads them into a file
    {
        try
        {
            File f = new File(filename);
            FileOutputStream fo = new FileOutputStream(f);
            ObjectOutputStream ou = new ObjectOutputStream(fo);
            ou.writeObject(o);
            ou.close();
        }
        catch (IOException e)
        {
            System.out.println(e);
        }

    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int roll; String name; double score;
        StudentWrite ob1 = new StudentWrite();
        System.out.println("Enter filename: ");
        ob1.filename = sc.nextLine();
        System.out.println("Enter 1 to store objects\n2 to read objects.");
        int ch = Integer.parseInt(sc.nextLine());
        switch(ch)
        {
          case 1:   System.out.println("Enter your roll: ");
                    roll = Integer.parseInt(sc.nextLine());
                    System .out.println("Enter your name: ");
                    name = sc.nextLine();
                    System.out.println("Enter your score: ");
                    score = Double.parseDouble(sc.nextLine());
                    Student temp = new Student(roll, name, score);   
                    ob1.write(temp);
                    break;
          case 2: ob1.read();
                    break;
          default: System.out.println("Invalid input.");
        }
        sc.close();
    }
}