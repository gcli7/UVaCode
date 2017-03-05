import java.util.*;

public class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );		
		String input = null;
		int l = 0, counter = 0;
		boolean flag = true;

		while( sc.hasNext() ) {
			input = sc.nextLine();
			l = input.length();
			flag = false;
			counter = 0;

			for( int i = 0 ; i < l ; i++ ) {
				if( ( (int)input.charAt( i ) >= (int)'a' && (int)input.charAt( i ) <= (int)'z' ) || ( (int)input.charAt( i ) >= (int)'A' && (int)input.charAt( i ) <= (int)'Z' ) )
					flag = true;

				else if( flag == true ) {
					flag = false;
					counter++;
				}
				else if( flag == true && i == l-1 )
					counter++; 
			}

			System.out.println( counter );
		}
	}
}