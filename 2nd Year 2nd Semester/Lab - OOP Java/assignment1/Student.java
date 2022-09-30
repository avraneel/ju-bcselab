import java.util.*;

class Student {
    int roll;
    String name;
    double score;
       
    void setData(int r, String n, double s) {
        roll = r;
        name = n;
        score = s;
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
        Student s1 = new Student();
        Student s2 = new Student();
        s1.setData(1, "Ram", 20);
        s2.copy(s1);
        s1.getData();
        s2.getData();
    }
}
