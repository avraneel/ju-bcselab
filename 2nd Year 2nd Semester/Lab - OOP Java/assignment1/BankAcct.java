import java.util.*;

class BankAcct {
    long acno;
    double bal;
    double rate;

    BankAcct()
    {
    	acno = 0;
    	bal = 0;
    	rate = 0;
    }
    
    BankAcct(long a, double b) {
    	acno = a;
    	bal = b;
    	rate = 5.0;
    }
    
    void setRate(double r) {
        rate = r;
        System.out.println("Rate = " + rate);
    }

    void calc() {
	bal = bal + ((rate/100) * bal);
	
	System.out.println("Balance = " + bal);
    }

    public static void main(String args[]) {
    	Scanner sc = new Scanner(System.in);
    	long ac;
    	double bal, r;
    	int ch;
    	System.out.println("Enter account number and balance: ");
    	ac = sc.nextLong();
    	bal = sc.nextDouble();
    	BankAcct b = new BankAcct(ac, bal);
        while(true) {
        	System.out.println("Enter:\n1 to set rate\n2 to calculate interest\n0 to exit");
        	ch = sc.nextInt();
        	if(ch == 0)
        		break;
        	switch(ch) {
        		case 1: System.out.println("Enter rate: ");
        			r = sc.nextDouble();
        			b.setRate(r);
        			break;
        		case 2: b.calc();
        			break;
        		default: System.out.println("Invalid input");
        	}
        	
        }
    }
}
