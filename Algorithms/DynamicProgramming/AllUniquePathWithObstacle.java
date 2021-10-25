package recurssion;

import java.util.Scanner;

public class AllUniquePathWithObstacle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] obstacleGrid = new int[n][m];
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    obstacleGrid[i][j] = sc.nextInt();
                }
            }
            System.out.println(uniquePathsWithObstacles(obstacleGrid));
        }
    }

    public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] path = new int[m][n];
        
        if( obstacleGrid[0][0] == 1 ){
            return 0;
        }
        
        path[0][0] = 1;
        
        for(int i = 1; i<m; i++){
            if( obstacleGrid[i][0] == 0 && path[i-1][0] == 1 ){
                path[i][0] = 1;
            }else{
                path[i][0] = 0;
            }
        }
        
        for(int i = 1; i<n; i++){
            if( obstacleGrid[0][i] == 0 && path[0][i-1] == 1 ){
                path[0][i] = 1;
            }else{
                path[0][i] = 0;
            }
        }
        
        
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if( obstacleGrid[i][j] == 1) {
                    path[i][j] = 0;
                }else{
                    path[i][j] = path[i-1][j] + path[i][j-1];
                }
            }
        }
        return path[m-1][n-1];
    }
}
