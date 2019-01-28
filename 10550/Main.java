import java.util.*;
import java.math.BigInteger;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		int start = 0, first = 0, second = 0, third = 0, sum = 0;
		
		while( true ) {
			start = sc.nextInt();
			first = sc.nextInt();
			second = sc.nextInt();
			third = sc.nextInt();
			if( first == 0 && second == 0 && third == 0 && start == 0 )
				break;
			sum = 360 * 3;
			
			if( start >= first )
				sum += ( start - first ) * 9;
			else
				sum += ( start + ( 40 - first ) ) * 9;
			
			if( first <= second )
				sum += ( second - first ) * 9;
			else
				sum += ( ( 40 -  first ) + second ) * 9;
			
			if( second >= third )
				sum += ( second - third ) * 9;
			else
				sum += ( second + ( 40 - third ) ) * 9;
			
			System.out.println( sum );
		}
	}
}