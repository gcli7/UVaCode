import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		long cases = sc.nextLong();
		sc.nextLine();
		while( cases-- > 0 ) {
			String input = sc.nextLine();
			input = input.replaceAll( " ", "" );
			
			int sum = 0, temp = 0;
			for( int i = 0 ; i < input.length() ; i += 2 ) {
				temp = Integer.parseInt( input.substring( i, i+1 ) );
				temp *= 2;
				if( temp >= 10 ) {
					sum += temp % 10;
					sum += temp / 10;
				}
				else
					sum += temp;
			}
			
			for( int i = 1 ; i < input.length() ; i += 2 )
				sum += Integer.parseInt( input.substring( i, i+1 ) );
			
			if( sum % 10 == 0 )
				System.out.println( "Valid" );
			else
				System.out.println( "Invalid" );
		}
	}
}