import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] argv) {
		Scanner sc = new Scanner(System.in);

		String[] output = new String[1001];

		output[0] = "1";
		output[1] = "2";
		for(int i = 2; i < 1001; i++) {
			BigInteger temp = new BigInteger(output[i-1]);
			output[i] = temp.add(new BigInteger(output[i-2])).toString();
		}

		int input = 0;
		while(sc.hasNext()) {
			input = sc.nextInt();

			System.out.println(output[input]);
		}
	}
}