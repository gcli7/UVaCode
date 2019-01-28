import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long cases = sc.nextLong();
		while( cases-- > 0 ) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			long forChange = sc.nextLong();
			long sunBottles = a + b;
			long sumDrink = 0;
			long getChange;
			
			while( sunBottles >= forChange ) {
				getChange = sunBottles / forChange;
				sumDrink += getChange;
				sunBottles %= forChange;
				sunBottles += getChange;
			}
			
			System.out.println( sumDrink );
		}
	}
}