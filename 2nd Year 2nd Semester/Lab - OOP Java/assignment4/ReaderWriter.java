import java.util.*;

class Value
{
    int v;

    Value(int v)
    {
        this.v = v;
    }

    int getVal()
    {
        return v;
    }
    
    void setVal(int x)
    {
        v = x;
    }

}

class ReadWriteLockPolicy
{
    int rcnt;
    int wcnt;
    int wrqcnt;

    ReadWriteLockPolicy()
    {
        rcnt = 0;
        wcnt = 0;
        wrqcnt = 0;
    }

    synchronized void readLock() throws InterruptedException
    {
        while(wcnt > 0 || wrqcnt > 0)
        {
            wait();
        }
        rcnt++;
    }

    synchronized void readUnlock() throws InterruptedException
    {
        rcnt--;
        notifyAll();
    }

    synchronized void writeLock() throws InterruptedException
    {
        wrqcnt++;
        while(wcnt > 0 || rcnt > 0)
        {
            wait();
        }
        wrqcnt--;
        wcnt++;
    }

    synchronized void writeUnlock() throws InterruptedException
    {
        wcnt--;
        notifyAll();
    }
}

class Reader implements Runnable
{
    int k;
    Value d;
    ReadWriteLockPolicy l;

    Reader(Value d, ReadWriteLockPolicy l)
    {
        this.d = d;
        this.l = l;
        k = 0;
    }

    public void run()
    {
        try
        {
            l.readLock();
            k = d.getVal();
            System.out.println("Value is = " + k);
            l.readUnlock();
        }
        catch(InterruptedException e)
        {
            System.out.println("An Interrputed Exception occured.");
        }
    }
}

class Writer implements Runnable
{
    int k;
    Value d;
    ReadWriteLockPolicy l;

    Writer(int k, Value d, ReadWriteLockPolicy l)
    {
        this.k = k;
        this.d = d;
        this.l = l;
    }

    public void run()
    {
        try
        {
            l.readLock();
            d.setVal(k);
            l.writeUnlock();
        }
        catch(InterruptedException e)
        {
            System.out.println("An Interrputed Exception occured.");
        }
    }
}

class ReaderWriter
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        ReadWriteLockPolicy l = new ReadWriteLockPolicy();
        System.out.println("Enter a value = ");
        int a = Integer.parseInt(sc.nextLine());
        Value d = new Value(a);
        Reader r = new Reader(d, l);
        Reader r2 = new Reader(d, l);
        System.out.println("Enter value to be updated = ");
        int x = Integer.parseInt(sc.nextLine());
        sc.close();
        Writer w = new Writer(x, d, l);
        Thread rt = new Thread(r);
        Thread rt2 = new Thread(r2);
        //Thread rt3 = new Thread(r);
       // Thread rt4 = new Thread(r);
        Thread wt = new Thread(w);
        //Thread wt2 = new Thread(w);
        rt.start();
        wt.start();
        rt2.start();
        //rt3.start();
        //rt4.start();
        try
        {
            rt.join();
            wt.join();
            rt2.join();
            //rt3.join();
            //rt4.join();
        }
        catch(InterruptedException e)
        {
            System.out.println("An Interrputed Exception occured.");
        }
    }
}
