import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long cases = sc.nextLong();
		while( cases-- > 0 ) {
			long sum = sc.nextLong();
			long absDiff = sc.nextLong();
			
			if( absDiff > sum || ( absDiff % 2 == 0 && sum % 2 == 1 ) ) {
				System.out.println( "impossible" );
				continue;
			}
			
			if( ( sum - absDiff ) == 0 || ( sum - absDiff ) % 2 == 0 )
				System.out.println( ( sum - absDiff ) / 2 + absDiff + " " + ( sum - absDiff ) / 2 );
			else
				System.out.println( "impossible" );
		}
	}
}