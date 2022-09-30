import java.util.*;

class Height {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int cm;
        cm = sc.nextInt();
        double feet, inches;
        feet = cm/30.5;
        inches = cm/2.54;
        System.out.println("Feet = " + feet); 
        System.out.println(" Inches = " + inches);
    }
}