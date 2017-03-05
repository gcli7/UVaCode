import java.util.*;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		String a = "", b = "";
		int l_a = 0, l_b = 0, counter = 0;
		boolean carry = true;
		
		while( true ) {
			a = sc.next();
			b = sc.next();
			if( a.equals( "0" ) && b.equals( "0" ) )
				break;
			l_a = a.length();
			l_b = b.length();
			carry = false;
			counter = 0;
			
			int i = l_a-1, j = l_b-1;
			for( ; i >= 0 && j >= 0 ; i--, j-- ) {
				if( carry ){
					if( (int)a.charAt( i ) + (int)b.charAt( j ) - ( 2 * (int)'0' ) >= 9  ) {
						carry = true;
						counter++;
					}
					else {
						carry = false;
					}
				}
				else {
					if( (int)a.charAt( i ) + (int)b.charAt( j ) - ( 2 * (int)'0' ) > 9  ) {
						carry = true;
						counter++;
					}
					else {
						carry = false;
					}
				}
			}
			if( i < 0 && j >= 0 ) {
				for( ; j >= 0 ; j-- ) {
					if( carry && ( (int)b.charAt( j ) == (int)'9' ) )
						counter++;
					else
						break;
				}
			}
			else if( j < 0 && i >= 0 ) {
				for( ; i >= 0 ; i-- ) {
					if( carry && ( (int)a.charAt( i ) == (int)'9' ) )
						counter++;
					else
						break;
				}
			}
			
			if( counter == 0 )
				System.out.println( "No carry operation." );
			else if( counter == 1 )
				System.out.println( counter + " carry operation." );
			else
				System.out.println( counter + " carry operations." );
				
		}
	}
}