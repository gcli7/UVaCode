import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		String[] base = new String[1001];
		base[0] = "1";
		base[1] = "1";
		BigInteger temp;

		for(int i = 2; i < 1001; i++) {
			temp = new BigInteger(base[i-1]);
			temp = temp.multiply(new BigInteger(String.valueOf(i)));
			base[i] = temp.toString();
		}

		Scanner sc = new Scanner(System.in);
		int input = 0;

		while(sc.hasNext()) {
			input = sc.nextInt();
			System.out.println(input + "!");
			System.out.println(base[input]);
		}
	}
}