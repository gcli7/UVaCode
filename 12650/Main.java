import java.util.*;

class Main {
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		
		while( sc.hasNext() ) {
			int allDivers = sc.nextInt();
			int returnDivers = sc.nextInt();
			boolean[] divers = new boolean[10005];
			int temp = 0, i = 0;
			for( i = 0 ; i < returnDivers ; i++ ) {
				temp = sc.nextInt();
				divers[temp] = true;
			}
			
			boolean flag = true;
			for( i = 1 ; i <= allDivers ; i++ )
				if( !divers[i] ) {
					flag = false;
					System.out.print( i + " " );
					break;
				}
			for( i++ ; i <= allDivers ; i++ ) {
				if( !divers[i] )
					System.out.print( i + " " );
			}
			if( flag )
				System.out.print( "*" );
			System.out.println();
		}
	}
}