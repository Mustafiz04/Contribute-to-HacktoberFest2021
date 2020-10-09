package recurssion;

import java.util.Scanner;

public class AllUniquePaths {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int m = sc.nextInt();
            System.out.println(allUniquePathDP(n,m));
        }
    }

    private static int allUniquePath(int n, int m) {
        if( n == 1 || m == 1 ){
            return 1;
        }

        return allUniquePath(n-1, m) + allUniquePath(n, m-1);
    }

    private static long allUniquePathDP(int n, int m) {
        long[][] mat = new long[n][m];
    
        long d = 1000000007;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if( i == 0 || j == 0 ){
                    mat[i][j] = 1;
                }else{
                    mat[i][j] = (mat[i-1][j] + mat[i][j-1])%d;
                }
            }
        }
        return mat[n-1][m-1];
    }
}
