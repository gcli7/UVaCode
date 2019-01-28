import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while( sc.hasNext() ) {
			int firChannel = sc.nextInt();
			int secChannel = sc.nextInt();
			if( firChannel == -1 && secChannel == -1 )
				break;

			int min;
			if( firChannel > secChannel ) {
				min = firChannel;
				firChannel = secChannel;
				secChannel = min;
			}	
			min = secChannel - firChannel;

			if( ( 100 - secChannel ) + ( firChannel - 0 ) < min )
				min = ( 100 - secChannel ) + ( firChannel - 0 );

			System.out.println( min );
		}
	}
}