import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		final String[] months = { " ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		
		int cases = sc.nextInt();
		int casesCounter = 0;
		sc.nextLine();
		while( cases-- > 0 ) {
			casesCounter++;
			String input = sc.nextLine();
			String[] startDate = input.split(" |,");
			input = sc.nextLine();
			String[] endDate = input.split(" |,");
			long[] start = new long[3];
			long[] end = new long[3];
			
			for( int i = 1 ; i <= 12 ; i++ ) {
				if( startDate[0].equals( months[i] ) ) {
					start[0] = Long.parseLong( startDate[3] );
					start[1] = i;
					start[2] = Long.parseLong( startDate[1] );
				}
				if( endDate[0].equals( months[i] ) ) {
					end[0] = Long.parseLong( endDate[3] );
					end[1] = i;
					end[2] = Long.parseLong( endDate[1] );
				}
			}
			
			if( start[1] <= 2 )
				start[0]--;
			start[0] = start[0] / 4 - start[0] / 100 + start[0] / 400;
			if( end[1] == 1 || ( end[1] == 2 && end[2] < 29 ) )
				end[0]--;
			end[0] = end[0] / 4 - end[0] / 100 + end[0] / 400;
					
			System.out.println( "Case " + casesCounter + ": " + Math.abs( end[0] - start[0] ) );
		}
	}
}