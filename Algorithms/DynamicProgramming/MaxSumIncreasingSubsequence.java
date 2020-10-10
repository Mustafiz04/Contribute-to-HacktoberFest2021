import java.io.*;
import java.util.*;
class GfG{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int Arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSumIS(Arr,n));
                }
        }
} 

class Solution{
	public int maxSumIS(int arr[], int n)  {
	    int[] mat = new int[n];
	    for(int i = 0; i<n; i++){
	        mat[i] = arr[i];
	    }
	    
	    int max = 0;
	    
	    for(int i = 1; i<n; i++){
	        for(int j = 0; j<i; j++){
	            if( arr[i] > arr[j] && mat[i] < mat[j] + arr[i] ){
	                mat[i] = mat[j] + arr[i];
	            }
	        }
	    }
	    
	    for(int i = 0; i<n; i++){
	        if( max < mat[i] ){
	            max = mat[i];
	        }
	    }
	    
	    return max;
	    
	}  
}