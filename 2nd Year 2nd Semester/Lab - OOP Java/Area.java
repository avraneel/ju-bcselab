import java.util.*;

class Area {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        final double pi = 3.14;
        double r;
        r = sc.nextDouble();
        double area;
        area = (pi * r * r); 
        System.out.println("Area = " + area); 
    }
}