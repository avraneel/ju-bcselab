import java.util.*;

class Metric {

    void k2m(double k) {
        double m = k / 1.5;
        System.out.println(m);
    }

    void m2k(double m) {
        double k = m * 1.5;
        System.out.println(k);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
		Metric ob = new Metric();
        double x;
        do {
            System.out.println("Enter value = ");
            x = sc.nextDouble();
			System.out.println("Enter 1 for kilometer to mile \n 2 for mile to kilometer \n 0 to exit");
            int c = sc.nextInt();
            if(c == 0) break;
            else if(c == 1) 
                ob.k2m(x);
            else if ( c == 2)
                ob.m2k(x);
        } while (true);
    }
}
