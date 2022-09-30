package Transaction;

public class TransactionEntry
{
    String memberId;
    String bookId;

    TransactionEntry(String bookId, String memberId)
    {
        this.bookId = bookId;
        this.memberId = memberId;
    }
    
    void modify(String bookId, String memberId)
    {
        this.bookId = bookId;
        this.memberId = memberId;
    }

    public void modifyBookId(String bookId)
    {
        this.bookId = bookId;
    }
    
    public void modifyMemberId(String memberId)
    {
        this.memberId = memberId;
    }

    public void disp()
    {
        System.out.println("Transaction details:");
        System.out.println("Book ID: " + bookId);
        System.out.println("Member ID: " + memberId);
    }
    
}