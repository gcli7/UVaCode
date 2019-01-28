import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		boolean flag = false;
		while( true ) {
			int players = sc.nextInt();
			if( players == 0 )
				break;
			if( flag )
				System.out.println();
			flag = true;
			
			long rounds = sc.nextInt();
			sc.nextLine();
			long[] win = new long[105];
			long[] lose = new long[105];
			rounds = rounds * players * ( players - 1 ) / 2;
			while( rounds-- > 0 ) {
				String input = sc.nextLine();
				String[] play = input.split( " " );
				
				if( ( play[1].equals( "rock" ) && play[3].equals( "scissors" ) ) || 
					( play[1].equals( "paper" ) && play[3].equals( "rock" ) ) ||
					( play[1].equals( "scissors" ) && play[3].equals( "paper" ) ) ) {
						win[Integer.parseInt( play[0] )]++;
						lose[Integer.parseInt( play[2] )]++;
				}
				else if( ( play[1].equals( "rock" ) && play[3].equals( "paper" ) ) || 
						 ( play[1].equals( "paper" ) && play[3].equals( "scissors" ) ) ||
						 ( play[1].equals( "scissors" ) && play[3].equals( "rock" ) ) ) {
							 lose[Integer.parseInt( play[0] )]++;
							 win[Integer.parseInt( play[2] )]++;
				}
			}
			
			for( int i = 1 ; i <= players ; i++ ) {
				if( ( win[i] + lose[i] ) == 0 )
					System.out.printf( "-" );
				else
					System.out.printf( "%.3f", (double)win[i] / ( win[i] + lose[i] ) );
				System.out.println();
			}
		}
	}
}