import java.util.*;

import BookList.*;
import MemberList.*;
import Transaction.*;

public class Library implements libraryManage
{
    ListOfBooks bl;
    ListOfMembers ml;
    ListOfTransactionEntries tl;

    static Scanner sc = new Scanner(System.in);
    static final int maxBook = 5;
    static final int maxMember = 5;

    Library(int maxBook, int maxMember)
    {
        bl = new ListOfBooks(maxBook);
        ml = new ListOfMembers(maxMember);
        tl = new ListOfTransactionEntries();
    }

    public void addBook()
    {
        String bookId, title;
        int purchased;
        System.out.println("Enter Book ID:");
        bookId = sc.nextLine();
        if(bl.exists(bookId) < 0)
        {
            System.out.println("Enter Title:");
            title = sc.nextLine();
            System.out.println("Enter no. of copies:");
            purchased = Integer.parseInt(sc.nextLine());
            Book b = new Book(bookId, title, purchased, purchased);
            bl.addBook(b);
        }
        else
            System.out.println("Book already exists.");
    }

    public int searchBook()
    {
        System.out.println("Enter book ID: ");
        String bookId = sc.nextLine();
        int bookIndex = bl.exists(bookId);
        return bookIndex;
    }
    
    public void viewAllBooks()
    {
        bl.dispall();
    }

    public void addMember()
    {
        String memberId, name, dob;
        System.out.println("Enter Member ID:");
        memberId = sc.nextLine();
        if(ml.exists(memberId) < 0)
        {
            System.out.println("Enter name:");
            name = sc.nextLine();
            System.out.println("Enter date of birth:");
            dob = sc.nextLine();
            Member m = new Member(memberId, name, dob, 0);
            ml.addMember(m);
        }
        else
            System.out.println("Member already exists!");

    }

    public int searchMember()
    {
        System.out.println("Enter member ID: ");
        String memberId = sc.nextLine();
        int memberIndex = ml.exists(memberId);
        return memberIndex;
    }
    
    public void viewAllMembers()
    {
        ml.dispall();
    }

    public void issueBook(String memberId, String bookId)
    {
        int memberIndex = ml.exists(memberId);
        int bookIndex = bl.exists(bookId);
        if(memberIndex < 0)
            System.out.println("Member not registered.");
        else if(bookIndex < 0)
            System.out.println("Book not registered.");
        else if(!ml.getMember(memberIndex).isEligible())
            System.out.println("Member has already reached issue limit.");
        else if(!bl.getBook(bookIndex).isAvailable())
            System.out.println("Book is not available.");
        else
        {
            bl.getBook(bookIndex).setAvailable(-1);
            ml.getMember(memberIndex).setIssued(1);
            tl.update(bookId, memberId);
            int transactionIndex = tl.exists(bookId, memberId);
            tl.getTransactionEntry(transactionIndex).disp();
        }
    }

    public void returnBook(String memberId, String bookId)
    {
        int memberIndex = ml.exists(memberId);
        int bookIndex = bl.exists(bookId);
        int transactionIndex = tl.exists(bookId, memberId);
        if(memberIndex < 0)
            System.out.println("Member not registered.");
        else if(bookIndex < 0)
            System.out.println("Book not registered.");
        else if(transactionIndex < 0)
            System.out.println("You have not issued this book.");
        else
        {
            bl.getBook(bookIndex).setAvailable(1);
            ml.getMember(memberIndex).setIssued(-1);
            tl.getTransactionEntry(transactionIndex).modifyMemberId("xxxx");
            System.out.println("Book has been returned.");
        }
    }


    public static void main(String[] args) 
    {
        int bookIndex, memberIndex, c = 0, n, limit;
        String memberId, bookId;
        Library ob = new Library(maxBook, maxMember);
        System.out.println("Enter maximum no. of books a member can issue.");
        System.out.println("Default is 5. Press 0 for default. ");
        limit = Integer.parseInt(sc.nextLine());
        if(limit < 1)
            ob.ml.setLimit(5);
        else
            ob.ml.setLimit(limit);
        do {
            System.out.println("Enter:");
            System.out.println("1 to add book");
            System.out.println("2 to add more copies for a book");
            System.out.println("3 to show all book details");
            System.out.println("4 to show details of a book");
            System.out.println("5 to add member");
            System.out.println("6 to show all members");
            System.out.println("7 to show details of a member");
            System.out.println("8 to issue a book");
            System.out.println("9 to return a book");
            System.out.println("0 to quit");
            c = Integer.parseInt(sc.nextLine());
            switch(c)
            {
                case 1: ob.addBook();
                        break;
                case 2: bookIndex = ob.searchBook();
                        if(bookIndex >= 0)
                        {
                            System.out.println("How many copies?");
                            n = Integer.parseInt(sc.nextLine());
                            ob.bl.getBook(bookIndex).addCopies(n);
                        }
                        else 
                            System.out.println("Book not registered.");
                        break;
                case 3: ob.viewAllBooks();
                        break;
                case 4: bookIndex = ob.searchBook();
                        if(bookIndex >= 0)
                            ob.bl.getBook(bookIndex).disp();
                        else 
                            System.out.println("Book not registered.");
                        break;
                case 5: ob.addMember();
                        break;
                case 6: ob.viewAllMembers();
                        break;
                case 7: memberIndex = ob.searchMember();
                        if(memberIndex >= 0)
                            ob.ml.getMember(memberIndex).disp();
                        else 
                            System.out.println("Member not registered.");
                        break;
                case 8: System.out.println("Enter member ID: ");
                        memberId = sc.nextLine();
                        System.out.println("Enter book ID: ");
                        bookId = sc.nextLine();
                        ob.issueBook(memberId, bookId);
                        break;
                case 9: System.out.println("Enter member ID: ");
                        memberId = sc.nextLine();
                        System.out.println("Enter book ID: ");
                        bookId = sc.nextLine();
                        ob.returnBook(memberId, bookId);
                        break;
                case 0: System.out.println("Thank you for using the library.");
                        break;
                default: System.out.println("Invalid input");
            }
            System.out.println();
        } while(c != 0);
        sc.close();
    }
}