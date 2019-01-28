import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] argv) {
		Scanner sc = new Scanner(System.in);

		String[] base = new String[101];
		BigInteger temp;

		base[0] = "1";
		for(int i = 1; i <= 100; i++) {
			temp = new BigInteger(base[i-1]);
			base[i] = temp.multiply(new BigInteger(Integer.toString(i))).toString();
		}

		int x = 0, y = 0;

		while(sc.hasNext()) {
			x = sc.nextInt();
			y = sc.nextInt();

			if(x == 0 && y == 0)
				break;

			String output = "0";
			if(x >= y) {
				temp = new BigInteger(base[x]);
				output = temp.divide(new BigInteger(base[y])).toString();
				temp = new BigInteger(output);
				output = temp.divide(new BigInteger(base[x-y])).toString();
			}
			
			System.out.println(x + " things taken " + y + " at a time is " + output + " exactly.");
		}
	}
}