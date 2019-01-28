import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner keyin = new Scanner( System.in );
		
		while( keyin.hasNext( ) ) {
			long input = keyin.nextLong( ), sum = 0;
			
			if( input == 0 )
				break;
			
			sum = 1;
			for( long i = 2 ; i <= input ; i++ )
				sum += i * i;
						
			System.out.println( sum );
		}
	}
}