import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		while( true ) {
			int cases = sc.nextInt();
			if( cases == 0 )
				break;
			
			int divisionPointX = sc.nextInt();
			int divisionPointY = sc.nextInt();
			int coordinateX = 0, coordinateY = 0;
			while( cases-- > 0 ) {
				coordinateX = sc.nextInt();
				coordinateY = sc.nextInt();
				if( coordinateX == divisionPointX || coordinateY == divisionPointY )
					System.out.println( "divisa" );
				else if( coordinateX > divisionPointX && coordinateY > divisionPointY )
					System.out.println( "NE" );
				else if( coordinateX > divisionPointX && coordinateY < divisionPointY )
					System.out.println( "SE" );
				else if( coordinateX < divisionPointX && coordinateY < divisionPointY )
					System.out.println( "SO" );
				else
					System.out.println( "NO" );
			}
		}
	}
}