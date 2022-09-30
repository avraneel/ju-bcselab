import java.util.*;

class EmpArray
{
    ArrayList<Department> dlist;
    ArrayList<Employee> elist;

    EmpArray()
    {
        dlist = new ArrayList<Department>();
        elist = new ArrayList<Employee>();
    }

    int searchEmployee(int empcode)
    {
        for(int i = 0; i < elist.size(); i++)
        {
            if(elist.get(empcode).equals(elist.get(i)))
                return i;
        }
        return -1;
    }

    int searchDepartment(int deptcode)
    {
        for(int i = 0; i < dlist.size(); i++)
        {
            if(elist.get(deptcode).equals(elist.get(i)))
                return i;
        }
        return -1;
    }

    void addEmp(Employee e)
    {
        if(searchEmployee(e.getcode()) == -1)
        {
            elist.add(e);
        }
    }

    void addDept(Department d)
    {
        if(searchDepartment(d.getcode()) == -1)
        {
            dlist.add(d);
        }
    }

    void disp(int empcode)
    {
        int i = searchEmployee(empcode);
        if(i != -1)
        {
            Employee e = elist.get(i);
            e.disp();
        }
    }

    void dispall()
    {
        for(int i = 0; i < elist.size(); i++)
        {
            Employee e = elist.get(i);
            e.disp();
        }
    }

    void findTotalBasicPay(int deptcode)
    {
        double sum = 0;
        int index = searchDepartment(deptcode);
        if(index == -1)
        {
            System.out.println("Department does not exist.");
            return;
        }
        for(int i = 0; i < elist.size(); i++)
        {
            if(elist.get(i).getDepcode() == deptcode)
                sum += elist.get(i).getBasic();
        }
        System.out.println("Total basic pay for department " + deptcode + " is = " + sum);
    }

    void remove(int empcode)
    {
        int i = searchEmployee(empcode);
        if(i == -1)
        {
            System.out.println("Employee does not exist.");
            return;
        }
        Employee e = elist.remove(i);
        e.disp();
    }

    public static void main(String[] args) {
        int empcode, deptcode;
        String name, location;
        double basic;
        Scanner sc = new Scanner(System.in);
        EmpArray ea = new EmpArray();
        System.out.println("Enter 1 to add employee\n2 to add dept\n3 to display specific employee\n4 to display all employees\n5 for total basic pay\6 to remove employee");
        System.out.println("0 to close");
        int c = Integer.parseInt(sc.nextLine());
        switch(c)
        {
            case 1: System.out.println("Enter empcode, name, basic, deptcode:");
                    empcode = Integer.parseInt(sc.nextLine());
                    name = sc.nextLine();
                    basic = Double.parseDouble(sc.nextLine());
                    deptcode = Integer.parseInt(sc.nextLine());
                    Employee e = new Employee(empcode, name, basic, deptcode);
                    ea.addEmp(e);
                    break;
            case 2: System.out.println("Enter deptcode, nname, location:");
                    deptcode = Integer.parseInt(sc.nextLine());
                    name = sc.nextLine();
                    location = sc.nextLine();
                    Department d = new Department(deptcode, name, location);
                    ea.addDept(d);
                    break;
            case 3: System.out.println("Enter employee code = ");
                    empcode = Integer.parseInt(sc.nextLine());
                    ea.disp(empcode);
                    break;
            case 4: ea.dispall();
                    break;
            case 5: System.out.println("Enter department code = ");
                    deptcode = Integer.parseInt(sc.nextLine());
                    ea.findTotalBasicPay(deptcode);
                    break;
            case 6: System.out.println("Enter employee code = ");
                    empcode = Integer.parseInt(sc.nextLine());
                    ea.remove(empcode);
                    break;
            default: System.out.println("Invalid input.");
            sc.close();
        }
    }
}