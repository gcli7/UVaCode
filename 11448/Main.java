import java.util.*;
import java.math.BigInteger;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );

		long cases = sc.nextLong();
		while( cases-- > 0 ) {
			String input1 = sc.next();
			String input2 = sc.next();
			
			BigInteger a = new BigInteger( input1 );
			BigInteger b = new BigInteger( input2 );
			
			System.out.println( a.add( new BigInteger( "-" + b ) ) );
		}
	}
}