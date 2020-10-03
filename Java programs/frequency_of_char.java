package virtusa_practise;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Duplicates {

	public static void main(String[] arg) {
		String x="abcabcd";
		char arr[]=x.toCharArray();
		Map<Character,Integer> map=new HashMap();
		int f[]=new int[arr.length];
		for(int i=0;i<arr.length;i++)
		{
//			f[i]=1;
//			for(int j=i+1;j<arr.length;j++)
//			{
//				if(arr[i]==arr[j])
//				{
//					f[i]++;
//					arr[j]='0';
					if(map.containsKey(arr[i]))
					    map.put(arr[i],map.get(arr[i])+1);
					else
						 map.put(arr[i],1);
//				}
//				else
//				{
//					
//				}
//			}
		}
		
		Set<Character> set=map.keySet();
		
		for(char c:set)
		{
			System.out.println("frequency of "+c+" is "+map.get(c));
		}
//		for(int i=0;i<arr.length;i++)
//		{
//			if(arr[i]!='0')
//			{
//				System.out.println("value is: "+arr[i]+"frequency is : "+f[i]);
//			}
//		}
	}
}
