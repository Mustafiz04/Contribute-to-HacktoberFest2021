// As another example, if the given sequence is “BBABCBCAB”, then the output
// should be 7 as “BABCBAB” is the longest palindromic subsequence in it.
// “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence,
// but not the longest ones. 

// The naive solution for this problem is to
// generate all subsequences of the given sequence and find the longest
// palindromic subsequence. This solution is exponential in term of time
// complexity. Let us see how this problem possesses both important properties
// of a Dynamic Programming (DP) Problem and can efficiently be solved using
// Dynamic Programming.

public class longest_pallindromic_subsequence {
   static int t[][];

   static int lcs(char x[], char y[], int m, int n) {
      for (int i = 1; i < x.length + 1; i++) {
         for (int j = 1; j < y.length + 1; j++) {
            if (x[i - 1] == y[j - 1]) {
               t[i][j] = 1 + t[i - 1][j - 1];
            } else {
               t[i][j] = Math.max(t[i - 1][j], t[i][j - 1]);
            }
         }
      }
      return t[m][n];
   }

   public static void main(String[] args) {
      String x = "BBABCBCAB";
      String y = new StringBuffer(x).reverse().toString();
      int m = x.length();
      int n = y.length();
      t = new int[m + 1][n + 1];
      int lps = lcs(x.toCharArray(), y.toCharArray(), m, n);
      System.out.println("Longest Pallindromic Subsequence Length : " + lps);
   }
}
