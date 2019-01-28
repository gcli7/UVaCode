import java.util.*;
import java.math.BigInteger;

public class Main {
	public static void main( String[] argv ) {
		Scanner sc = new Scanner( System.in );

		int cases = sc.nextInt();
		while( cases-- > 0 ) {
			sc.nextLine();
			String number = sc.nextLine(), divisor;
			int s = sc.nextInt(), i = 0;
			int set[] = new int[12];
			BigInteger bigN;

			for( i = 0 ; i < s ; i++ )
				set[i] = sc.nextInt();

			bigN = new BigInteger( number );
			for( i = 0 ; i < s ; i++ ) {
				divisor = Integer.toString( set[i] );
				if( bigN.mod( new BigInteger( divisor ) ).toString() != "0" )
					break;
			}

			if( i == s )
				System.out.println( number + " - Wonderful." );
			else
				System.out.println( number + " - Simple." );
		}
	}
}