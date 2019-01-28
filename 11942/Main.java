import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		int cases = sc.nextInt();
		System.out.println( "Lumberjacks:" );
		while( cases-- > 0 ) {
			int[] input = new int[10];
			for( int i = 0 ; i < 10 ; i++ )
				input[i] = sc.nextInt();
			
			int positiveCounter = 0, negativeCounter = 0;
			for( int i = 1 ; i < 10 ; i++ )
				if( input[i] - input[i-1] > 0 )
					positiveCounter++;
				else
					negativeCounter++;
				
			if( ( positiveCounter == 0 && negativeCounter == 9 ) || ( positiveCounter == 9 && negativeCounter == 0 ) )
				System.out.println( "Ordered" );
			else
				System.out.println( "Unordered" );
		}
	}
}