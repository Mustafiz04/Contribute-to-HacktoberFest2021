import java.util.HashMap;
import java.util.Set;

public class frequency_of_char {

	public static void main(String[] arg) {
		String x = "abcabcd";
		char arr[] = x.toCharArray();
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		for (int i = 0; i < arr.length; i++) {
			if (map.containsKey(arr[i]))
				map.put(arr[i], map.get(arr[i]) + 1);
			else
				map.put(arr[i], 1);
		}
		Set<Character> set = map.keySet();
		for (char c : set) {
			System.out.println("Frequency of " + c + " is " + map.get(c));
		}

	}
}
