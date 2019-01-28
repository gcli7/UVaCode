import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		while( true ) {
			String input = sc.nextLine();
			if( input.equals( "*" ) )
				break;
			
			int correctCounter = 0;
			String[] measure = input.split( "/" );
			for( int i = 1 ; i < measure.length ; i++ ) {
				int sum = 0;
				for( int k = 0 ; k < measure[i].length() ; k++ )
					sum += duration( measure[i].charAt( k ) );
				
				if( sum == 64 )
					correctCounter++;
			}
			
			System.out.println( correctCounter );
		}
	}
	
	private static int duration( char c ) {
		int r = 0;
		switch( c ) {
			case 'W':
				r = 64;	break;
			case 'H':
				r = 32;	break;
			case 'Q':
				r = 16;	break;
			case 'E':
				r = 8;	break;
			case 'S':
				r = 4;	break;
			case 'T':
				r = 2;	break;
			case 'X':
				r = 1;	break;
			default:
				break;
		}
		
		return r;
	}
}