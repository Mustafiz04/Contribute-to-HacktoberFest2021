public class FiboDP {
    static int n=5;

    static int fib[] = new int[n + 1];

    public static void answer() {
        for (int i = 0; i < n+1; i++) {
            fib[i] = -1;
        }
    }

//Memoization

    public static int fibTopDown(int n, int fib[]) {
        if (fib[n] == -1) {
            if (n <= 1) {
                fib[n] = n;
            } else {
                fib[n] = fibTopDown(n - 1, fib) + fibTopDown(n - 2, fib);
            }
        }
        return fib[n];
    }

//Bottom-UP

    public static int fibBottomUp(int n) {
        int[] fib = new int[n + 1];
        fib[0] = 0;
        fib[1] = 1;

        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        return fib[n];
    }

    public static void main(String[] args) {
        answer();
        System.out.println( n+"th Fibonacii term using MEMOIZATION technique : " + fibTopDown(n, fib));
        System.out.println(n+"th Fibonacii term using Bottom-UP technique  : " + fibBottomUp(n));
    }
}
