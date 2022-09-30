import java.util.*;

class Data
{
    int v;

    Data(int v)
    {
        this.v = v;
    }

    synchronized void increment(int x)
    {
        v += x;
        System.out.println("Updated value = " + v);
    }

    synchronized void decrement(int x)
    {
        v -= x;
        System.out.println("Updated value = " + v);
    }

    synchronized int getData()
    {
        return v;
    }
}

class Thread1 implements Runnable
{
    Data d;
    int x;

    Thread1(Data d, int x)
    {
        this.d = d;
        this.x = x;
    }

    public void run()
    {
        d.increment(x);
    }
}

class Thread2 implements Runnable
{
    Data d; 
    int x; 
    
    Thread2(Data d, int x)
    {
        this.d = d;
        this.x = x;
    }

    public void run()
    {
        d.decrement(x);
    }
}

class MutualExclusion
{
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter a value = ");
        int a = Integer.parseInt(sc.nextLine());
        Data d = new Data(a);
        System.out.println("Enter value to increment = ");
        int x = Integer.parseInt(sc.nextLine());
        System.out.println("Enter value to decrement = ");
        int y = Integer.parseInt(sc.nextLine());
        Thread1 th1 = new Thread1(d, x);
        Thread2 th2 = new Thread2(d, y);
        Thread t1 = new Thread(th1);
        Thread t2 = new Thread(th2);
        t1.start();
        t2.start();
        try
        {
            t1.join();
            t2.join();
        }
        catch(InterruptedException e)
        {
            System.out.println("An Interrupted Exception occured");
        }
        System.out.println("Final Value = " + d.getData());
        sc.close();        
    }
}