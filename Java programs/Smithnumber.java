import java.util.*;
class Smith
{
    //function for finding sum of digits
    int sumDig(int n)
    {
        int s=0;
        while(n>0)
        {
            s=s+n%10;
            n=n/10;
        }
        return s;
    }
 
    //function for generating prime factors and finding their sum
    int sumPrimeFact(int n)
    {
        int i=2, sum=0;
        while(n>1)
        {
            if(n%i==0)
            {
                sum=sum+sumDig(i); //Here 'i' is the prime factor of 'n' and we are finding its sum
                n=n/i;
            }
            else
                i++;
        }
        return sum;
    }
 
    //function to check for composite number
    boolean isComposite(int n)
    {
        int c=0;
        for(int i=1; i<=n; i++)
        {
            if(n%i==0)
            {
                c++;
            }
        }
        if(c>2)
            return true;
        else
            return false;
    }
 
    public static void main(String args[])
    {
        Smith ob=new Smith();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a Number : ");
        int n=sc.nextInt();
        if(ob.isComposite(n) == false)
        {
            System.out.println("You have entered a non-Composite Number. Please enter a composite number");
        }
        else
        {
            int a=ob.sumDig(n);// finding sum of digit
            int b=ob.sumPrimeFact(n); //finding sum of prime factors
 
            System.out.println("Sum of Digit = "+a);
            System.out.println("Sum of Prime Factor = "+b);
 
            if(a==b)
                System.out.print(n+" is a Smith Number");
            else
                System.out.print(n+" is Not a Smith Number");
        }
    }
}
