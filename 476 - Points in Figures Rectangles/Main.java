import java.util.*;

public class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		double[][] r_point = new double[11][4];
		double x = 0.0, y = 0.0;
		long r_counter = 0, p_counter = 0;
		boolean flag = true;
		
		String r = null;
		while( sc.hasNext() ) {
			r = sc.next();
			if( r.equals( "r" ) ) {
				r_counter++;
				for( int i = 0 ; i < 4 ; i++ )
					r_point[(int)r_counter-1][i] = sc.nextDouble();
			}
			else
				break;
		}
		
		while( sc.hasNext() ) {
			flag = true;
			p_counter++;
			x = sc.nextDouble();
			y = sc.nextDouble();
			
			if( x == 9999.9 && y == 9999.9 )
				break;
			
			for( int i = 0 ; i < r_counter ; i++ ) {
				if( x > r_point[i][0] && x < r_point[i][2] && y > r_point[i][3] && y < r_point[i][1] ) {
					System.out.println( "Point " + p_counter + " is contained in figure " + ( i+1 ) );
					flag = false;
				}
			}
			if( flag )
				System.out.println( "Point " + p_counter + " is not contained in any figure" );
		}
	}
}
