import java.io.*;
import java.util.*;

class NameManager
{    
    File file;
    int n;
    static Scanner sc = new Scanner(System.in);

    NameManager(File file)
    {
        this.file = file;
        n = 0;
    }
    
    void input()
    {
        try 
        {
            System.out.println("How many names you want to enter?");
            n = Integer.parseInt(sc.nextLine());
            String buffer;
            FileWriter fw = new FileWriter(file, true);
            PrintWriter pw = new PrintWriter(fw);
            for(int i = 0; i < n; i++) 
            {
                buffer = sc.nextLine();
                pw.println(buffer);
            }
            pw.close();
        } catch (IOException e) 
        {
            System.out.println("An IOException occured.");
        }
    }
    
    void output() 
    {
        try 
        {
            if(!file.exists()) {
                System.out.println("You need to store atleast 1 name to create the file.");
                return;
            }
            String buffer = "";
            Scanner scf = new Scanner(file);
            while(scf.hasNextLine())
            {
                buffer = scf.nextLine();
                System.out.println(buffer);
            }
            scf.close();
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File doesn't exist");
        }
    }

    public static void main(String[] args) {
        int ch = 0;
        String filename;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter filename with appropriate suffix:");
        filename = sc.nextLine();
        File f = new File(filename);
        NameManager ob = new NameManager(f);
        do
        {
            System.out.println("Enter:\n1 to store names\n2 to print names");
            System.out.println("0 to exit");
            ch = Integer.parseInt(sc.nextLine());
            switch(ch)
            {
                case 1: ob.input();
                        break;
                case 2: ob.output();
                        break;
                case 0: System.out.println("Thank you for using Name Manager.");
                        break;
                default: System.out.println("Invalid input.");
            }
        }while(ch != 0);
        sc.close();
    }
}