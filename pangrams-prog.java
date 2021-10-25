//we promptly judged antique ivory buckles for the next prize


import java.util.*;
public class pangrams
{
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		LinkedList<String> list=new LinkedList<String>();
		String s=sc.nextLine().toUpperCase();
		HashSet<String> set = new HashSet<String>();
		for(int i=65;i<=90;i++)
		{
			list.add(Character.toString((char)i));
		}
		
		for(int i=0;i<s.length();i++)
		{
			set.add(Character.toString(s.charAt(i)));
		}
//System.out.println(set);
		try{
		Iterator itr=set.iterator();
		while(itr.hasNext())
			list.remove(itr.next());
	}
	catch(Exception e)
	{}
	finally
	{
		if(list.size()==0)
			System.out.println("Pangram");
		else
			System.out.println("Not Pangram");
	}
	}
		
	
}
