import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		int cases = sc.nextInt();
		sc.nextLine();
		while( cases-- > 0 ) {
			String input = sc.nextLine();
			int leftSum = ( (int)input.charAt( 0 ) - (int)'A' ) * 26 * 26 + ( (int)input.charAt( 1 ) - (int)'A' ) * 26 + ( (int)input.charAt( 2 ) - (int)'A' );
			int rightSum = Integer.parseInt( input.substring( 4 ) );
			
			if( Math.abs( leftSum - rightSum ) <= 100 )
				System.out.println( "nice" );
			else
				System.out.println( "not nice" );
		}
	}
}