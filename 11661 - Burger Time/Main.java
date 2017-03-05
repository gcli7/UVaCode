import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while( sc.hasNext() ) {
			long length = sc.nextLong();
			sc.nextLine();
			if( length == 0 )
				break;
			
			String highway = sc.nextLine();
			
			if( highway.contains("Z") ) {
				System.out.println( "0" );
				continue;
			}

			int i;
			char ch = ' ';
			for  ( i = 0 ; i < highway.length() ; i++ )
				if( highway.charAt(i) == 'D' ) {
					ch = 'D';
					break;
				}
				else if ( highway.charAt(i) == 'R' ) {
					ch = 'R';
					break;
				}
				
			long distance = 2000000, lastIndex = i;
			for ( ++i ; i < highway.length() ; i++ ) {
				if( highway.charAt(i) != '.' ) {
					if( highway.charAt(i) != ch  ) {
						ch = highway.charAt(i);
						if( i - lastIndex < distance )
							distance = i - lastIndex;
					}
					lastIndex = i;
				}
			}
			
			System.out.println( distance );
		}
	}
}