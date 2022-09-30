package MemberList;

public class ListOfMembers 
{
    Member list[];
    int cur, temp;

    public ListOfMembers(int maxMember)
    {
        list = new Member[maxMember];
        cur = 0;
    }
    
    public Member getMember(int i)
    {
        return list[i];
    }
    
    public int exists(String memberId)         //checks if member exists
    {
        for(int i = 0; i < cur; i++)  
        {
            if(i < list.length && list[i].memberId.equals(memberId))
                return i;
        }
        return -1;
    }
    
    public void addMember(Member m)
    {
        try
        {
            list[cur++] = m;
            System.out.println("Member added.");
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Maximum member limit reached.");
        }
    }

    public void setLimit(int limit)
    {
        Member.limit = limit;
    }
    
    public void dispall()
    {
        for(int i = 0; i < cur; i++)
            if(i < list.length)
                list[i].disp();
    }
}
