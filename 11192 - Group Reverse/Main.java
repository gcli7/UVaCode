import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while( sc.hasNext() ) {
			int group = sc.nextInt();
			if( group == 0 )
				break;
			
			String input = sc.next();
			final int part = input.length() / group;
			
			for( int i = 1 ; i <= group ; i++ )
				for( int j = 1 ; j <= part ; j++ ) {
					System.out.print( input.charAt( i * part - j ) );
				}
			System.out.println( );
		}
	}
}