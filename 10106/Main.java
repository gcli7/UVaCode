import java.util.*;
import java.math.BigInteger;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		
		while( sc.hasNext() ) {
			String input1 = sc.nextLine();
			String input2 = sc.nextLine();
			
			BigInteger a = new BigInteger( input1 );
			BigInteger b = new BigInteger( input2 );
			
			System.out.println( a.multiply( b ) );
		}
	}
}