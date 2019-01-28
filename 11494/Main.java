import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner keyin = new Scanner( System.in );
		
		while( keyin.hasNext( ) ) {
			long x1 = keyin.nextLong( ), y1 = keyin.nextLong( ), x2 = keyin.nextLong( ), y2 = keyin.nextLong( );
			
			if( x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 )
				break;
			
			if( x1 == x2 && y1 == y2 )
				System.out.println( "0" );
			else if( x1 == x2 || y1 == y2 || ( x2 - x1 ) + ( y2 - y1 ) == 0 || ( x2 - x1 ) - ( y2 - y1 ) == 0 )
				System.out.println( "1" );
			else
				System.out.println( "2" );
		}
	}
}