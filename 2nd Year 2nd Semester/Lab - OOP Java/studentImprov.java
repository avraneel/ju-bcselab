import java.util.*;

class studentImprov {
    int roll;
    String name;
    double score;
       
    Student() {
        roll = 0;
        name = "";
        score = 0;
    }
    
    Student(int roll) {
        this.roll = roll;
        name = "";
        score = 0;
    }

    Student(int roll, String name) {
        this.roll = roll;
        this.name = name;
        score = 0;
    }

    Student(int roll, String name, double score) {
        this.roll = roll;
        this.name = name;
        this.score = score;
    }
    
    
    void setData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter data: ");
        roll = sc.nextInt();
        name = sc.next();
        score = sc.nextDouble();
    }

    void getData() {
        System.out.println("Roll = " + roll);
        System.out.println("Name = " + name);
        System.out.println("Score = " + score);
    }

    void copy(Student s) {
        this.roll = s.roll;
        this.name = s.name;
        this.score = s.score;
    }

    public static void main(String args[]) {
        Student s1 = new Student(3);
        Student s2 = new Student(1, "Ram");
        Student s3 = new Student(1, "Ram", 35);
        Student s4 = new Student();
    }
}