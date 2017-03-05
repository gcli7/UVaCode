import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long cases = sc.nextLong();
		long counter = 0;
		while( ++counter <= cases ) {
			int x = sc.nextInt();
			int outputIndex = ( x - 1 ) / 2;
			int[] input = new int[9];

			for( int i = 0 ; i < x ; i++ )
				input[i] = sc.nextInt();

			System.out.println("Case " + counter + ": " + input[outputIndex] );
		}
	}
}