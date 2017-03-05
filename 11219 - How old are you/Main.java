import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		int cases = sc.nextInt();
		sc.nextLine();
		int casesCounter = 0;
		while( ++casesCounter <= cases ) {
			sc.nextLine();
			String nowDate = sc.nextLine();
			String bornDate = sc.nextLine();
			
			String[] now = nowDate.split( "/" );
			String[] born = bornDate.split( "/" );
			int[] n = { Integer.parseInt( now[0] ), Integer.parseInt( now[1] ), Integer.parseInt( now[2] ) };
			int[] b = { Integer.parseInt( born[0] ), Integer.parseInt( born[1] ), Integer.parseInt( born[2] ) };
			
			if( isInvalid( n, b ) )
				System.out.println( "Case #" + casesCounter + ": Invalid birth date" );
			else {
				int yearOld = n[2] - b[2];
				if( b[1] > n[1] )
					yearOld--;
				else if( b[1] == n[1] && b[0] > n[0] )
					yearOld--;
				
				if( yearOld <= 130 )
					System.out.println( "Case #" + casesCounter + ": " + yearOld );
				else
					System.out.println( "Case #" + casesCounter + ": Check birth date" );
			}
		}
	}
	
	private static boolean isInvalid( int[] now, int[] born ) {
		if( now[2] < born[2] )
			return true;
		
		if( now[2] == born[2] && now[1] < born[1] )
			return true;
		
		if( now[2] == born[2] && now[1] == born[1] && now[0] < born[0] )
			return true;
		
		return false;
	}
}