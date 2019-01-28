import java.util.*;

public class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		long cases = sc.nextLong();
		while( cases-- > 0 ) {
			int relatives = sc.nextInt();
			int[] streetNumber = new int[503];
			
			for( int i = 0 ; i < relatives ; i++ )
				streetNumber[i] = sc.nextInt();
			
			int temp = 0;
			for( int i = relatives - 1 ; i > 0 ; i-- )
				for( int j = 0 ; j < i ; j++ )
					if( streetNumber[j] > streetNumber[j+1] ) {
						temp = streetNumber[j];
						streetNumber[j] = streetNumber[j+1];
						streetNumber[j+1] = temp;
					}
			
			long sumDistances = 0;
			if( relatives % 2 == 1 ) {
				int vitoHouse = streetNumber[relatives/2];
				for( int i = 0 ; i < relatives / 2 ; i++ )
					sumDistances += vitoHouse - streetNumber[i];
				for( int i = relatives / 2 + 1 ; i < relatives ; i++ )
					sumDistances += streetNumber[i] - vitoHouse;
			}
			else {
				long sum1 = 0, sum2 = 0;
				int vitoHouse = streetNumber[relatives/2];
				for( int i = 0 ; i < relatives / 2 ; i++ )
					sum1 += vitoHouse - streetNumber[i];
				for( int i = relatives / 2 + 1 ; i < relatives ; i++ )
					sum1 += streetNumber[i] - vitoHouse;
				
				vitoHouse = streetNumber[(relatives/2)-1];
				for( int i = 0 ; i < relatives / 2 - 1 ; i++ )
					sum2 += vitoHouse - streetNumber[i];
				for( int i = relatives / 2 ; i < relatives ; i++ )
					sum2 += streetNumber[i] - vitoHouse;
				
				if( sum1 < sum2 )
					sumDistances = sum1;
				else
					sumDistances = sum2;
			}
			
			System.out.println( sumDistances );
		}
	}
}