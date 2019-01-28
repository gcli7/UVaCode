import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		long casesCounter = 0;
		while( sc.hasNext() ) {
			casesCounter++;
			
			int inputCases = sc.nextInt();
			long[] input = new long[20];
			int zeroCounter = 0, negativeCounter = 0;
			for( int i = 0 ; i < inputCases ; i++ ) {
				input[i] = sc.nextLong();
				if( input[i] == 0 )
					zeroCounter++;
				if( input[i] < 0 )
					negativeCounter++;
			}
			
			long sum = 1, tempSum = 1;
			if( zeroCounter == 0 && negativeCounter == 0 ) {
				for( int i = 0 ; i < inputCases ; i++ )
					sum *= input[i];
			}
			else if( inputCases == 1 && input[0] <= 0 ) {
				sum = 0;
			}
			else {
				boolean flag = true;
				for( int i = 0 ; i < inputCases ; i++ ) {
					if( input[i] == 0 ) {
						if( tempSum > sum )
							sum = tempSum;
						tempSum = 1;
						continue;
					}
					else if( input[i] < 0 ) {
						int index = i, k = 0, firstNegative = i;
						negativeCounter = 0;
						for( k = i+1 ; k < inputCases ; k++ ) {
							if( input[k] == 0 )
								break;
							else if( input[k] < 0 ) {
								negativeCounter++;
								index = k;
							}
						}
						
						if( k == inputCases && negativeCounter % 2 == 1 ) {
							index = inputCases - 1;
						}
						else if( negativeCounter % 2 == 0 ) {
							index--;
						}
						else {
							index = k -1;
						}
						
						for( k = i ; k <= index ; k++ ) {
							tempSum *= input[k];
							flag = false;
						}
						
						if( tempSum > sum )
							sum = tempSum;
						tempSum = 1;
					}
					else {
						tempSum *= input[i];
						flag = false;
					}
				}
				if( tempSum > sum )
					sum = tempSum;
				if( flag )
					sum = 0;
			}
			System.out.println( "Case #" + casesCounter + ": The maximum product is " + sum + "." );
			System.out.println();
		}
	}
}