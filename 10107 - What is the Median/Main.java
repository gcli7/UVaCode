import java.util.*;
import java.util.ArrayList;

public class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		ArrayList<Long> input = new ArrayList<Long>();
		long temp = 0;
		int length = 0;
		temp = sc.nextInt();
		input.add( temp );
		System.out.println( temp );
		while( sc.hasNext() ) {
			temp = sc.nextInt();
			input.add( temp );
			Collections.sort(input);
			length = input.size();
			if( length % 2 == 0 )
				System.out.println( ( input.get( length / 2 ) + input.get( ( length / 2 ) - 1 ) ) / 2 );
			else
				System.out.println( input.get( length / 2 ) );
		}
	}
}