import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		while( true ) {
			String input = sc.nextLine();
			if( input.equals( "0" ) )
				break;
			
			BigInteger bn = new BigInteger( input );
			if( bn.mod( new BigInteger( "17" ) ).toString().equals( "0" ) )
				System.out.println( "1" );
			else
				System.out.println( "0" );
		}
	}
}