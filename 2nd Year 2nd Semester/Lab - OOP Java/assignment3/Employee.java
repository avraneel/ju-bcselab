class Employee
{
    int empcode;
    String empname;
    double basic;
    int deptcode;

    Employee(int empcode, String empname, double basic, int deptcode)
    {
        this.empcode = empcode;
        this.empname = empname;
        this.basic = basic;
        this.deptcode = deptcode;
    }

    void disp()
    {
        System.out.println("Emp code = " + empcode);
        System.out.println("Employee name = " + empname);
        System.out.println("Basic pay = " + basic);
        System.out.println("Department code = " + deptcode);
    }

    void setBasic(int basic)
    {
        this.basic = basic;
    }

    int getcode()
    {
        return empcode;
    }

    double getBasic()
    {
        return basic;
    }

    int getDepcode()
    {
        return deptcode;
    }
}