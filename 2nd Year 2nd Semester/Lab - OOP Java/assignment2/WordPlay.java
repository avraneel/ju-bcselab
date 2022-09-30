import java.util.*;

class WordPlay 
{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String s, wd;
		int ch, n, c1 = 0, c2 = 0;
		System.out.println("Enter a string: ");
		s = sc.nextLine();
		s = s.trim();
		while(true)
		{
			System.out.println("Enter:\n1 to find out number of times 'a' appears\n2 to find out number of times \"and\" appears\n3 to find out whether the string starts with \"The\" or not\n4 To display tokens\n0 to exit");
			ch = Integer.parseInt(sc.next()); 
			if(ch == 0)
				System.exit(0);
			StringTokenizer st = new StringTokenizer(s, " @.");
			switch(ch)
			{
				case 1: for(int i = 0; i < s.length(); i++)
						if(s.charAt(i) == 'a')
							c1++;
					System.out.println("No. of times 'a' appears is: " + c1); 
					break;
				case 2: while(st.hasMoreTokens())
					{
						wd = st.nextToken();
						if(wd.equals("and"))	c2++;
					}
					System.out.println("No. of times \"and\" appears is: " + c2); 
					break;
				case 3: if(st.nextToken().equals("The"))
						System.out.println("Starts with \"The\"");
					else
						System.out.println("Does not start with \"The\"");
					break;
				case 4: n = st.countTokens();
					System.out.println("Number of tokens is: " + n);
					break;
				default: System.out.println("Invalid input");
			}
		}
	}
}
		
	

