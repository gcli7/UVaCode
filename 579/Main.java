import java.util.*;

public class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		String input = null;
		int hour = 0, minute = 0;
		double h_degree = 0.0, m_degree = 0.0, sum = 0.0;

		while( true ) {
			input = sc.nextLine();
			if( input.substring( 1, 2 ).equals( ":" ) ) {
				hour = Integer.parseInt( input.substring( 0, 1) );
				minute = Integer.parseInt( input.substring( 2, 4) );
			}
			else {
				hour = Integer.parseInt( input.substring( 0, 2) );
				minute = Integer.parseInt( input.substring( 3, 5) );
			}
			if( hour == 0 )
				break;

			if( hour == 12 )
				hour = 0;
			h_degree = hour * 30 + minute * 0.5;
			m_degree = minute * 6;
			sum = h_degree - m_degree;
			if( sum < 0.0 )
				sum = 0.0 - sum;
			if( sum > 180.0 )
				sum = 360.0 - sum;

			System.out.printf( "%.3f", sum );
			System.out.println();
		}
	}
}