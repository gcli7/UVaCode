import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long cases = sc.nextLong();
		sc.nextLine();
		while( cases-- > 0 ) {
			String input = sc.nextLine();
			int[] output = new int[26];
			int l = input.length();
			
			for( int i = 0 ; i < l ; i++ ) {
				if( (int)input.charAt(i) >= (int)'A' && (int)input.charAt(i) <= (int)'Z' ) {
					output[(int)input.charAt(i) - (int)'A']++;
				}
				else if( (int)input.charAt(i) >= (int)'a' && (int)input.charAt(i) <= (int)'z' ) {
					output[(int)input.charAt(i) - (int)'a']++;
				}
			}
			
			int max = 0;
			for( int i = 0 ; i < 26 ; i++ )
				if( output[i] > max )
					max = output[i];
				
			for( int i = 0 ; i < 26 ; i++ )
				if( output[i] == max )
					System.out.print( (char)(i + (int)'a') );
			System.out.println();
		}
	}
}