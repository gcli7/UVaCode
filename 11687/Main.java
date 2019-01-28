import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		while( true ) {
			int counter = 1;
			String input = sc.nextLine();
			if( input.equals( "END" ) )
				break;
			
			long digitsNumber = input.length();
			if( input.equals( Long.toString( digitsNumber ) ) ) {
				System.out.println( "1" );
				continue;
			}
			
			while( true ) {
				counter++;
				long nextNumber = Long.toString( digitsNumber ).length();
				if( nextNumber == digitsNumber ) {
					System.out.println( counter );
					break;
				}
				digitsNumber = nextNumber;
			}
		}
	}
}