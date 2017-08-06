import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String[] base = new String[1001];
		base[0] = "1";
		int[] answer = new int[1001];
		answer[0] = 1;
		BigInteger big_temp;
		int sum = 0;

		for(int i = 1; i <= 1000; i++) {
			big_temp = new BigInteger(base[i-1]);
			base[i] = big_temp.multiply(new BigInteger(String.valueOf(i))).toString();
			sum = 0;
			for(int j = 0; j < base[i].length(); j++)
				sum += (int)base[i].charAt(j) - (int)'0';
			answer[i] = sum;
		}

		while(sc.hasNext()) {
			int input = sc.nextInt();
			System.out.println(answer[input]);
		}
	}
}