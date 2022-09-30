package Transaction;

public class ListOfTransactionEntries {
    TransactionEntry list[] = null;
    int cur;

    public ListOfTransactionEntries()
    {
        list = new TransactionEntry[100];
        cur = 0;
    }
    
    public TransactionEntry getTransactionEntry(int i)
    {
        return list[i];
    }
    
    public void update(String bookId, String memberId)
    {
        try
        {    
            list[cur] = new TransactionEntry(bookId, memberId);
            cur++;
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Array index out of bounds");
        }
    }

    public int exists(String bookId, String memberId)
    {
        for(int i = 0; i < cur; i++)  
        {
            if(i < list.length && list[i].memberId.equals(memberId) && list[i].bookId.equals(bookId)) 
                return i;        
        }
        return -1;
    }

    public void dispall()
    {
        for(int i = 0; i < cur; i++)
            list[i].disp();
    }
}
