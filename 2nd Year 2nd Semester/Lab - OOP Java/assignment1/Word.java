import java.util.*;

class Word {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String s = "";
        System.out.println("Enter a string = ");
        s = sc.next();
        String p = s;
        boolean a, b, c, d;
        a = (p == s);
        b = p.equals(s);
        System.out.println("First case");
        System.out.println(a);
        System.out.println(b);
        String x = sc.next();
        String y = sc.next();
        c = (x == y);
        d = x.equals(y);
        System.out.println("Second case");
        System.out.println(c);
        System.out.println(d);
    }
}
