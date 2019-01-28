import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		int cases = sc.nextInt();
		int casesCounter = 0;
		while( ++casesCounter <= cases ) {
			double initialTemperature = sc.nextDouble();
			double increaseTemperature = sc.nextDouble();
			
			initialTemperature = ( 1.8 * initialTemperature ) + 32 + increaseTemperature;
			initialTemperature = ( initialTemperature - 32 ) / 1.8;
			
			System.out.printf( "Case %d: %.2f\n", casesCounter, initialTemperature );
		}
	}
}