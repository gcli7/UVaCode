import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long cases = sc.nextLong();
		long caseCounter = 0;
		while( ++caseCounter <= cases ) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			long c = sc.nextLong();
			
			System.out.print( "Case " + caseCounter + ": " );
			if( ( a + b <= c ) || ( a + c <= b ) || ( c + b <= a ) )
				System.out.println( "Invalid" );
			else if ( a == b && b == c )
				System.out.println( "Equilateral" );
			else if ( a != b && b != c && c != a )
				System.out.println( "Scalene" );
			else
				System.out.println( "Isosceles" );
		}
	}
}