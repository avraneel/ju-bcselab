import java.util.*;

class student 
{
    int roll;
    String name;
    double score;

    void setScore(double s)
    {
        try {
            if(s < 0 || s > 100)
                throw new Exception("Score Exception.");
            score = s;
            System.out.println("Score updated.");
        }
        catch (Exception e)
        {
            System.out.println("Invalid score.");
        }
        finally
        {
            System.out.println("Your score is: " + score);
        }
    }

    public static void main(String args[]) 
    {
        double s; char ch;
        Scanner sc = new Scanner(System.in);
        student ob = new student();
        System.out.println("Enter roll: ");
        ob.roll = Integer.parseInt(sc.nextLine());
        System.out.println("Enter name: ");
        ob.name = sc.nextLine();
        System.out.println("Enter score: ");
        s = Double.parseDouble(sc.nextLine());
        ob.setScore(s);
        do 
        {
            System.out.println("Do you want to set score again?\nEnter:\ny for yes\nany other key for no");
            ch = sc.next().charAt(0);
            if(ch == 'y')
            {
                System.out.println("Enter new score:");
                s = sc.nextDouble();
                ob.setScore(s);
            }
            else 
                break;
        } while(true);
        sc.close();
    }
}