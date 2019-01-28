import java.util.*;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		long c = sc.nextLong();
		int cases = 0, counter = 0;
		double sum = 0;
		int[] grade = new int[1005];
		
		while( c-- > 0 ) {
			cases = sc.nextInt();
			counter = 0;
			sum = 0.0;
			for( int i = 0 ; i < cases ; i++ ) {
				grade[i] = sc.nextInt();
				sum += (double)grade[i];
			}
			sum /= cases;
			
			for( int i = 0 ; i < cases ; i++ )
				if( grade[i] > sum)
					counter++;
			
			System.out.printf( "%.3f%%\n", (double)counter / cases * 100 );
		}
	}
}