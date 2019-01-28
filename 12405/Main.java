import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();
		int casesCounter = 0; 
		while( ++casesCounter <= cases ) {
			int fields = sc.nextInt();
			String temp = sc.nextLine();
			temp = sc.nextLine();
			char[] field = temp.toCharArray();

			int scarecrows = 0;
			int counter = 0;
			for( int i = 0 ; i < fields ; i++ ) {
				if( counter == 0 && i == fields - 1 && field[i] == '.' )
					scarecrows++;

				else if( counter == 0 && field[i] == '#' )
					continue;

				else if( counter == 0 && field[i] == '.' )
					counter++;

				else if( counter == 1 ) {
					counter = 0;
					scarecrows++;
					i++;
				}
			}

			System.out.println( "Case " + casesCounter + ": " + scarecrows );
		}
	}
}