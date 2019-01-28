import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String[] output = new String[80];
		output[0] = "1";
		output[1] = "2";
		BigInteger bi;

		for( int i = 2 ; i < 80 ; i++ ) {
			bi = new BigInteger( output[i-2] );
			output[i] = bi.add( new BigInteger( output[i-1] ) ).toString();
		}

		while( sc.hasNext() ) {
			int input = sc.nextInt();
			if( input == 0 )
				break;

			System.out.println( output[input-1] );
		}
	}
}