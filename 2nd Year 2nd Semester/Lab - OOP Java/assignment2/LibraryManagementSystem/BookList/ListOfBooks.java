package BookList;

public class ListOfBooks
{
    Book list[];
    int cur;

    public ListOfBooks(int maxBook)
    {
        list = new Book[maxBook];
        cur = 0;
    }
    
    public Book getBook(int i)
    {
            return list[i];
    }
    
    public int exists(String bookId)
    {
        for(int i = 0; i < cur; i++)      //checking uniqueness
        {
            if(i < list.length && list[i].bookId.equals(bookId))
                return i;     
        }
        return -1;
    }
    
    public void addBook(Book b)
    {
        try
        {
            list[cur++] = b;
            System.out.println("Book added.");
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Maximum book limit reached.");
        }
    }

    public void dispall()
    {
        for(int i = 0; i < cur; i++)
            if(i < list.length)
                list[i].disp();
    }
}
