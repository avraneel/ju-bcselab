package BookList;

public class Book
{
    String bookId;
    String title;
    int purchased;
    int available;

    public Book()
    {
        bookId = "";
        title = "";
        purchased = 0;
        available = 0;
    }

    public Book(String bookId, String title, int purchased, int available)
    {
        this.bookId = bookId;
        this.title = title;
        this.purchased = purchased;
        this.available = available;
    }

    public void addCopies(int n)
    {
        purchased += n;
        available += n;
    }

    public void setAvailable(int n)
    {
        available += n;
    }

    public boolean isAvailable()
    {
        return (available > 0 ? true : false);
    }

    public void disp()
    {
        System.out.println("Book Details:");
        System.out.println("Book ID: " + bookId);
        System.out.println("Title: " + title);
        System.out.println("Total no. of copies purchased: " + purchased);
        System.out.println("No. of copies currently available: " + available);
    }
}       

