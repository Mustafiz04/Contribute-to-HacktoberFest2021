import java.util.*;
public class Palindrome
{
public static void main(String args[])
{
Scanner in=new Scanner(System.in);
int n,d=0,n2=0,nc;
System.out.println("Enter a Number:");
n=in.nextInt();
nc=n;
while(n>0)
{
d=n%10;
n2=(n2*10)+d;
n=n/10;
}
if(n2==nc)
System.out.println("Palindrome Number");
else
System.out.println("NON PALINDROME NUMBER");
}
}

