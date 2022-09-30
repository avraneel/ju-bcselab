package MemberList;

public class Member
{
    String memberId;
    String name;
    String dob;
    int issued;

    static int limit = 5;

    public Member()
    {
        memberId = "";
        name = "";
        dob = "";
        issued = 0;
    }

    public Member(String memberId, String name, String dob, int issued) 
    {
        this.memberId = memberId;
        this.name = name;
        this.dob = dob;
        this.issued = issued;
    }

    public boolean isEligible()
    {
        return (issued < limit ? true : false);
    }

    public void setIssued(int n)
    {
        issued += n;
    }

    public void disp()
    {
        System.out.println("Meember Details:");
        System.out.println("Member ID: " + memberId);
        System.out.println("Name: " + name);
        System.out.println("Date of birth: " + dob);
        System.out.println("No. of books currently issued: " + issued + "/" + limit);
    }
}