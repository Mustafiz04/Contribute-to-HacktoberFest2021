import java.util.Arrays;

public class ArrayDemo {
   public static void main(String[] args) {

      // initializing unsorted Object array
      Object ob[] = {27, 11, 5, 44};

      // let us print all the elements available in list
      for (Object number : ob) {
         System.out.println("Number = " + number);
      }

      // sorting array from index 1 to 3
      Arrays.sort(ob, 1, 3);

      // let us print all the elements available in list
      System.out.println("Object array with some sorted values(1 to 3) is:");
      for (Object number : ob) {
         System.out.println("Number = " + number);
      }
   }
}
