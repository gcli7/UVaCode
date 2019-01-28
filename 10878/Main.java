import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner keyin = new Scanner( System.in );
		
		String input = keyin.nextLine( );
		while( keyin.hasNext( ) ) {
			int sum = 0, count = 6;
			
			input = keyin.nextLine( );
			if( input.charAt( 0 ) == input.charAt( 1 ) )
				break;
			
			for( int i = 2 ; input.charAt( i ) != '|' ; i++ ) {
				if( input.charAt( i ) == '.' )
					i++;
				if( input.charAt( i ) == ' ' )
					count--;
				else if( input.charAt( i ) == 'o' ) {
					sum += Math.pow( 2, count );
					count--;
				}
			}
			
			System.out.print( (char)sum );
		}
	}
}