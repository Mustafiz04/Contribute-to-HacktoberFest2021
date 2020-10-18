


import java.util.*;
public class weight
{
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		LinkedList<String> list=new LinkedList<String>();
		LinkedList<Integer> list3=new LinkedList<Integer>();
		String s=sc.nextLine().toUpperCase();
		int sum=0;
		int n=sc.nextInt();
		for(int j=0;j<n;j++)	
			list3.add(sc.nextInt());
		LinkedList<String> list2=new LinkedList<String>();
		for(int i=65;i<=90;i++)
		{
			list.add(Character.toString((char)i));
		}
		
		for(int i=0;i<s.length();i++)
		{
			list2.add(Character.toString(s.charAt(i)));
		}
		LinkedList<Integer> summ=new LinkedList<Integer>();
		LinkedList<Integer> l2=new LinkedList<Integer>();
//System.out.println(set);
		int c=0,p=0;
		try{
		Iterator itr=list2.iterator();
		while(itr.hasNext()){
			sum=0;
			sum+=(list.indexOf(itr.next())+1);
			summ.add(sum);
		}
		//list2.clear();
		for(int itr1:summ)
		{
			c=itr1;
			if(l2.contains(c)==true)
				p+=itr1;
			else
				p=c;
			
			l2.add(p);

		}
	}
	catch(Exception e)
	{}
	finally
	{
			Collections.sort(l2);
			for(int k:list3)
			{
				if(Collections.binarySearch(l2,k)>=0)
					System.out.println("Yes");
				else
					System.out.println("No");
			}

	}

	}

		
	
}
