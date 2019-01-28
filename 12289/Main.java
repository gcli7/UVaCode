import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner keyin = new Scanner( System.in );
		
		final char one[] = { 'o', 'n', 'e' }, two[] = { 't', 'w', 'o' }, three[] = { 't', 'h', 'r', 'e', 'e' };
		long cases = keyin.nextInt( );
		
		while( cases-- > 0 ) {			
			String input = keyin.next( );
			int count = 0;
			
			if( input.length( ) == 5 )
				System.out.println( "3" );
			else {
				for( int i = 0 ; i < input.length( ) ; i++ )
					if( !( input.charAt( i ) == one[i] ) )
						count++;
				
				if( count <= 1 )
					System.out.println( "1" );
				else
					System.out.println( "2" );
			}
		}
	}
}