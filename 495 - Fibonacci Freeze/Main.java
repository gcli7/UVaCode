import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String[] base = new String[5005];
		base[0] = "0";
		base[1] = "1";

		for(int i = 2; i <= 5000; i++)
			base[i] = ((new BigInteger(base[i-1])).add(new BigInteger(base[i-2]))).toString();

		while(sc.hasNext()) {
			int input = sc.nextInt();

			System.out.println("The Fibonacci number for " + input + " is " + base[input]);
		}
	}
}