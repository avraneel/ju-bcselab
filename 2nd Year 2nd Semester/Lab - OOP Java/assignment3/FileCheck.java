import java.util.*;
import java.io.*;

class FileCheck
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        String list[];
        System.out.println("Enter filename:");
        String filename = sc.nextLine();
        File f = new File(filename);
        if(!f.exists())
            System.out.println("Filename doesnt exist.");
        else
            System.out.println("Filename exists.");
        if(f.isDirectory())
        {
            System.out.println("Filename is a directory.");
            list = f.list();
            System.out.println("Listing it's contents:");
            if(list.length == 0)
                System.out.println("No files contained.");
            for(int i= 0; i < list.length; i++)
                System.out.println(list[i]);
        }
        else if(f.isFile())
        {
            System.out.println("Filename is a file.");
            if(f.canRead())
                System.out.println("File can be read");
            if(f.canWrite())
                System.out.println("File can be written into.");
        }
        sc.close();      
    }
}