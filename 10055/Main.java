import java.util.*;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		long a = 0, b = 0;
		
		while( sc.hasNext() ) {
			a = sc.nextLong();
			b = sc.nextLong();
			
			if( a < b )
				System.out.println( b - a );
			else
				System.out.println( a - b );
		}
	}
}