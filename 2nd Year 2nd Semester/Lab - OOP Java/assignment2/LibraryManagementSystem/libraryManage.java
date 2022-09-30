public interface libraryManage
{
    void addBook();
    int searchBook();
    void viewAllBooks();
    void addMember();
    int searchMember();
    void viewAllMembers();
    void issueBook(String memberId,  String bookId);
    void returnBook(String memberId, String bookId);
}