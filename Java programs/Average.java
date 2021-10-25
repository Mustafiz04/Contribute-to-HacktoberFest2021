import java.util.Scanner;

public class Average {
    static Scanner input = new Scanner(System.in);
    
    public static void main(String [] args){
        average();
    }
    
        public static void average(){
        System.out.println("Enter a group of numbers to get their average");
        
        System.out.println("How many numbers would you like to enter");
        //  The number variable takes an input of type int from the user        
        int number = input.nextInt();
        
        //  The numArray variable holds an array of integers, the size of the array depends on the value stored in the number 
        //  variable. 
        int numArray[] = new int[number];
        
        //  The sum variable will hold the sum of all the values in numArray and it is initially assigned to zero
        int sum = 0;
        
        //  For each iteration of the loop:
        //  1: a number is taken from the user and stored in the array
        //  2: the number is added to sum
        for(int i = 0; i < number; i++){
            System.out.println("Enter number " + (i + 1));
            numArray[i] = input.nextInt();
            sum = sum + numArray[i];
        } 
        
        //  The average variable stores the result of dividing the sum by the amount of numbers entered
        int average = sum / number;
        
        System.out.println("The average is " + average);
    }
}  
   
