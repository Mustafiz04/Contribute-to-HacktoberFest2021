import java.util.Scanner;
public class SumofNaturalnumbers{

	public static void main(String[]args){
		int x,y;
		Scanner s = new Scanner(System.in);
		System.out.print("Enter a natural number:");
		x = s.nextInt();
		
		y = sum(x);
		System.out.print("Sum of natural numbers up to " +x +" is :" +y);

	}	
	public static int sum(int a){

	if(a>0){
		return a+ sum (a-1);
	}
		else{	
			return 0;
		}
	
	}
}
		
		
