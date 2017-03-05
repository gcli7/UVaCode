import java.util.*;

public class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		while( true ) {
			String number = "", input = "";
			char flag = ' ';
			
			while( true ) {
				input = sc.next();
				if( input.equals( "#" ) || input.equals( "~" ) )
					break;
			
				if( input.equals( "0" ) )
					flag = '1';
				else if( input.equals( "00" ) )
					flag = '0';
				else
					for( int k = 0 ; k < input.length() - 2 ; k++ )
						number += flag;
			}
			
			if( input.equals( "~" ) )
				break;
			
			if( number.length() == 0 )
				number = "0";
			
			int output = 0;
			for( int i = number.length() - 1, n = 0 ; i >= 0 ; i--, n++ )
				if( number.charAt( i ) == '1' )
					output += Math.pow( 2 , n );
			
			System.out.println( output );
		}
	}
}