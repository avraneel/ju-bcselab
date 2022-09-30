import java.util.*;

class studentImprov {
    int roll;
    String name;
    double score;
       
    studentImprov() {
        roll = 100;
        name = "Default";
        score = 150;
    }
    
    studentImprov(int roll) {
        this.roll = roll;
        name = "Default";
        score = 150;
    }

    studentImprov(int roll, String name) {
        this.roll = roll;
        this.name = name;
        score = 150;
    }

    studentImprov(int roll, String name, double score) {
        this.roll = roll;
        this.name = name;
        this.score = score;
    }

    void getData() {
        System.out.println("Roll = " + roll);
        System.out.println("Name = " + name);
        System.out.println("Score = " + score);
    }

    studentImprov(studentImprov s) {
        this.roll = s.roll;
        this.name = s.name;
        this.score = s.score;
    }

    public static void main(String args[]) {
        studentImprov s1 = new studentImprov(3);
        studentImprov s2 = new studentImprov(1, "Ram");
        studentImprov s3 = new studentImprov(1, "Ram", 35);
        studentImprov s4 = new studentImprov();
        studentImprov s5 = new studentImprov(s3);
        s1.getData();
        s2.getData();
        s3.getData();
        s4.getData();
        s5.getData();
    }
}
