import java.util.*;

class BankAcct {
    long acno;
    double bal;
    static double rate;

    static void setRate(double r) {
        rate = r;
    }

    static void showRate() {
        System.out.println(rate);;
    }

    void calc() {

    }

    void showBal() {
        System.out.println("Balance = " + bal;)
    }
}