import java.util.*;
import java.math.BigInteger;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		String input = "";
		
		while( true ) {
			input = sc.nextLine();
			if( input.substring( 0 , 1 ).equals( "-" ) )
				break;
			
			if( input.equals( "1" ) ) {
				System.out.println( "0%" );
				continue;
			}
			else {
				BigInteger output = new BigInteger( input );
				System.out.println( output.multiply( new BigInteger( "25" ) ) + "%" );
			}
		}
	}
}