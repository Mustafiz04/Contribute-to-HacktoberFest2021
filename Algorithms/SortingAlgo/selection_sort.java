import java.util.Arrays;

public class selection_sort {
   public static void sort(int arr[]) {
      int n = arr.length;
      for (int i = 0; i < n - 1; i++) {
         int min = i;
         for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
               min = j;
         int temp = arr[min];
         arr[min] = arr[i];
         arr[i] = temp;
      }
   }

   public static void main(String args[]) {
      int arr[] = { 64, 25, 12, 10, 3, 22, 11, 8, 6 };
      sort(arr);
      System.out.println("Array after selection sort : ");
      System.out.println(Arrays.toString(arr));
   }
}
