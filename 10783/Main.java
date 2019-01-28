import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner keyin = new Scanner( System.in );
		
		long cases = keyin.nextInt( );
		long case_number = 0;
		
		while( cases-- > 0 ) {
			case_number++;
			
			long start = keyin.nextInt( );
			long end = keyin.nextInt( );
			long temp = 0, sum = 0;
			
			if( start > end ) {
				temp = start;
				start = end;
				end = temp;
			}
			
			if( start % 2 == 0 )
				start++;
			
			if( end % 2 == 0 )
				end--;
			
			while( start <= end ) {
				sum += start;
				start +=2;
			}
			
			System.out.println( "Case " + case_number + ": " + sum );
		}
	}
}