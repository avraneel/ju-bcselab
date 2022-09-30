class Department
{
    int deptcode;
    String deptname;
    String location;

    Department(int deptCode, String deptname, String location)
    {
        this.deptcode = deptCode;
        this.deptname = deptname;
        this.location = location;
    }

    void disp()
    {
        System.out.println("Dep code = " + deptcode);
        System.out.println("Dept name = " + deptname);
        System.out.println("Location = " + location);
    }

    int getcode()
    {
        return deptcode;
    }
}