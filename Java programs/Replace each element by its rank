import java.util.*;
class Rank{
public static void main(String[] args) {
Scanner sc=new Scanner(System.in);
int n=sc.nextInt(),a[]=new int[n],b[]=new int[n],i;
Map<Integer,Integer> map=new HashMap<Integer,Integer>();
for ( i=0;i<n;i++) 
a[i]=sc.nextInt();	
for ( i=0;i<n;i++) 
b[i]=a[i];	
Arrays.sort(a);
for ( i=0;i<n;i++) 
map.put(a[i],i);
for ( int j:b) 
System.out.println(map.get(j)+1);
}
}
