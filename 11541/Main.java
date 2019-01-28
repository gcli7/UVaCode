import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long cases = sc.nextLong();
		sc.nextLine();
		long casesCounter = 0;
		while( ++casesCounter <= cases ) {
			String input = sc.nextLine();
			int times = 0, startIndex = 0, endIndex = 0;
			char c = ' ';
			
			System.out.print( "Case " + casesCounter + ": " );
			for( int i = 0 ; i < input.length() ; i++ ) {
				if( (int)input.charAt(i) >= (int)'A' || (int)input.charAt(i) <= (int)'Z' ) {
					c = input.charAt(i);
					startIndex = i + 1;
					endIndex = startIndex;
					for( int j = startIndex ; j < input.length() && (int)input.charAt(j) >= (int)'0' && (int)input.charAt(j) <= (int)'9' ; j++, endIndex++ )
						;
					i = endIndex - 1;
					
					times = Integer.parseInt( input.substring( startIndex, endIndex ) );
					
					for( int j = 0 ; j < times ; j++)
						System.out.print( c );
				}
			}
			System.out.println();
		}
	}
}