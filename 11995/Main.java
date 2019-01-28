import java.util.*;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		ArrayList<Integer> q_list = new ArrayList<Integer>( );
		ArrayList<Integer> s_list = new ArrayList<Integer>( );
		ArrayList<Integer> pq_list = new ArrayList<Integer>( );
		boolean q = true, s = true, pq = true;
		int cases = 0, command = 0, data = 0, max = 0;
		
		while( sc.hasNext() ) {
			cases = sc.nextInt();

			q_list.clear();
			s_list.clear();
			pq_list.clear();
			q = true;
			s = true;
			pq = true;
			
			while( cases-- > 0 ) {
				command = sc.nextInt();
				data = sc.nextInt();
				
				if( command == 1 ) {
					q_list.add( data );
					s_list.add( data );
					pq_list.add( data );
				}
				else {
					if( q ) {
						if( q_list.size() != 0 && data == q_list.get( 0 ) )
							q_list.remove( 0 );
						else
							q = false;
					}
					if( s ) {
						if( s_list.size() != 0 && data == s_list.get( s_list.size()-1 ) )
							s_list.remove( s_list.size()-1 );
						else
							s = false;
					}
					if( pq ) {
						max = 0;
						for( int i = 0 ; i < pq_list.size() ; i++ )
							if( pq_list.get( i ) > max )
								max = pq_list.get( i );
						
						if( pq_list.size() != 0 && data == max )
							pq_list.remove( pq_list.indexOf( data ));
						else
							pq = false;
					}
				}
			}
			if( !q && !s && !pq )
				System.out.println( "impossible" );
			else if( q && !s && !pq )
				System.out.println( "queue" );
			else if( !q && s && !pq )
				System.out.println( "stack" );
			else if( !q && !s && pq )
				System.out.println( "priority queue" );
			else
				System.out.println( "not sure" );
		}
	}
}