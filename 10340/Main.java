import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner keyin = new Scanner( System.in );
		
		while( keyin.hasNext( ) ) {			
			String input1 = keyin.next( );
			String input2 = keyin.next( );
			int temp = -1, count = 0;
			
			for( int i = 0 ; i < input1.length( ) ; i++ )
				while( ++temp < input2.length( ) )
					if( input1.charAt( i ) == input2.charAt( temp ) ) {
						count++;
						break;
					}
			
			if( count == input1.length( ) )
				System.out.println( "Yes" );
			else
				System.out.println( "No" );
		}
	}
}