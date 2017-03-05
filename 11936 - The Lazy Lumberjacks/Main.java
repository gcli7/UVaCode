import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();
		while( cases-- > 0 ) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			long c = sc.nextLong();
			
			if( ( a + b <= c ) || ( a + c <= b ) || ( c + b <= a ) )
				System.out.println( "Wrong!!" );
			else
				System.out.println( "OK" );
		}
	}
}