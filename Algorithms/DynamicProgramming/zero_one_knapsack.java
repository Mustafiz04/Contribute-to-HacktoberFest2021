public class zero_one_knapsack {
   public static int knapsack(int wt[], int val[], int w, int n) {
      if (n == 0 || w == 0) {
         return 0;
      }
      if (wt[n - 1] <= w) {
         return Math.max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
      } else {
         return knapsack(wt, val, w, n - 1);
      }
   }

   public static void main(String[] args) {
      // weight array
      int wt[] = { 10, 20, 30 };
      // value array
      int val[] = { 60, 100, 120 };
      // capacity of the knapsack
      int w = 50;
      // number of the items
      int n = wt.length;
      System.out.println("Maximum value : " + knapsack(wt, val, w, n));
   }
}
