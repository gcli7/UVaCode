import java.util.*;

public class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		int cases = 0;
		long sum = 0, moves = 0, set = 0;
		int[] stacks = new int[101];

		while( sc.hasNext() ) {
			cases = sc.nextInt();
			if( cases == 0 )
				break;
			else {
				set++;
				sum = 0;
				moves = 0;
			}

			for( int i = 0 ; i < cases ; i++ ) {
				stacks[i] = sc.nextInt();
				sum += stacks[i];
			}
			sum /= cases;

			for( int i = 0 ; i < cases ; i++ ) {
				if( stacks[i] > sum )
					moves += stacks[i] - sum;
			}

			System.out.println( "Set #" + set );
			System.out.println( "The minimum number of moves is " + moves + "." );
			System.out.println();
		}
	}
}