import java.util.*;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		
		ArrayList<Long> f = new ArrayList<Long>();
		f.add( (long)1 );
		f.add( (long)2 );
		for( int i = 0 ; f.get( i ) + f.get( i+1 ) < 100000000 ; i++ )
			f.add( f.get( i ) + f.get( i+1 ) );
		
		long cases = sc.nextLong();
		long input = 0;
		final int l = f.size();
		while( cases-- > 0 ) {
			input = sc.nextLong();
			System.out.print( input + " = " );
			
			int i = 0;
			for( i = l-1 ; i >= 0 ; i-- )
				if( input >= f.get( i ) )
					break;
			
			for( int j = i ; j >= 0 ; j-- ) {
				if( input >= f.get( j ) ) {
					input -= f.get( j );
					System.out.print( 1 );
				}
				else
					System.out.print( 0 );
			}
			
			System.out.println( " (fib)" );
		}
	}
}