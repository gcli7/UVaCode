import java.util.*;

public class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		double[][] figures = new double[11][5];
		double x = 0.0, y = 0.0;
		long f_counter = 0, p_counter = 0;
		boolean flag = true;
		
		String c = null;
		while( sc.hasNext() ) {
			c = sc.next();
			if( c.equals( "r" ) ) {
				f_counter++;
				for( int i = 0 ; i < 4 ; i++ )
					figures[(int)f_counter-1][i] = sc.nextDouble();
				figures[(int)f_counter-1][4] = 1.0;
				c = sc.nextLine();
			}
			else if( c.equals( "c" ) ) {
				f_counter++;
				for( int i = 0 ; i < 3 ; i++ )
					figures[(int)f_counter-1][i] = sc.nextDouble();
				figures[(int)f_counter-1][4] = 2.0;
				c = sc.nextLine();
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
			
			for( int i = 0 ; i < f_counter ; i++ ) {
				if( figures[i][4] == 1.0 ) {
					if( x > figures[i][0] && x < figures[i][2] && y > figures[i][3] && y < figures[i][1] ) {
						System.out.println( "Point " + p_counter + " is contained in figure " + ( i+1 ) );
						flag = false;
					}
				}
				else
					if( ( ( x - figures[i][0] ) * ( x - figures[i][0] ) + ( y - figures[i][1] ) * ( y - figures[i][1] ) ) < figures[i][2] * figures[i][2] ) {
						System.out.println( "Point " + p_counter + " is contained in figure " + ( i+1 ) );
						flag = false;
					}
			}
			if( flag )
				System.out.println( "Point " + p_counter + " is not contained in any figure" );
		}
	}
}