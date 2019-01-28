import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner keyin = new Scanner( System.in );
		
		while( keyin.hasNext( ) ) {
			String input = keyin.nextLine( );
			long sum = 0, flag = 0;
			
			for( int i = 0 ; i < input.length( ) ; i++ ) {
				if( input.charAt( i ) >= 'a' && input.charAt( i ) <= 'z' )
					sum += (long)( input.charAt( i ) ) - 96;
				else if( input.charAt( i ) >= 'A' && input.charAt( i ) <= 'Z' )
					sum += (long)( input.charAt( i ) ) - 38;
			}
			
			for( int i = 2 ; i * i <= sum ; i++ )
				if( sum % i == 0 ) {
					flag = 1;
					break;
				}
			
			if( flag == 0 || sum == 1 || sum == 2 )
				System.out.println( "It is a prime word." );
			else
				System.out.println( "It is not a prime word." );
		}
	}
}