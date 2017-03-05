import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();
		while( cases-- > 0 ) {
			int items = sc.nextInt();
			int[] input = new int[20000];
			long sum = 0;
			int temp;
			
			for( int i = 0 ; i < items ; i++ )
				input[i] = sc.nextInt();
			
			Arrays.sort( input );
			
			for( int i = 19997 ; i >= 0 && input[i] != 0 ; i -= 3 )
				sum += input[i];
				
			System.out.println( sum );
		}
	}
}