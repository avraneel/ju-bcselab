import java.util.*;

class Word {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String s = "";
        System.out.println("Enter a string = ");
        s = sc.next();
        String p = s;
        boolean a, b;
        a = (p == s);
        b = p.equals(s);
        System.out.println("First case");
        System.out.println(a);
        System.out.println(b);
        String x = "abc";
        String y = "abc";
        a = (p == s);
        b = p.equals(s);
        System.out.println("First case");
        System.out.println(a);
        System.out.println(b);
    }
}