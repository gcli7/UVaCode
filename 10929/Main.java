import java.util.*;
import java.math.BigInteger;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		String input = "";
		
		while( true ) {
			input = sc. next();
			if( input.equals( "0" ) )
				break;
			
			BigInteger a = new BigInteger( input );
			BigInteger temp = a.divide( new BigInteger( "11" ) );
			if( temp.multiply( new BigInteger( "11" ) ).equals( a ) )
				System.out.println( input + " is a multiple of 11." );
			else
				System.out.println( input + " is not a multiple of 11." );
		}
	}
}