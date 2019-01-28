import java.util.*;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		boolean[] prime = new boolean[2002];
		prime[0] = false;
		prime[1] = false;
		prime[2] = true;
		for( int i = 3 ; i <= 2001 ; i++)
			prime[i] = p( i );
		
		int cases = 0, counter = 0;
		String input = "";
		
		cases = sc.nextInt();
		input = sc.nextLine();
		while( ++counter <= cases  ) {
			int[] times = new int[250];
			boolean flag = true;
			input = sc.nextLine();
			
			for( int i = 0 ; i < input.length() ; i++ )
				times[ (int)input.charAt( i ) ]++;
			
			System.out.print( "Case " + counter + ": " );
			for( int i = (int)'0' ; i <= (int)'9' ; i++ )
				if( prime[ times[i] ] ) {
					System.out.print( (char)i );
					flag = false;
				}
			for( int i = (int)'A' ; i <= (int)'Z' ; i++ )
				if( prime[ times[i] ] ) {
					System.out.print( (char)i );
					flag = false;
				}
			for( int i = (int)'a' ; i <= (int)'z' ; i++ )
				if( prime[ times[i] ] ) {
					System.out.print( (char)i );
					flag = false;
				}
			
			if( flag )
				System.out.println( "empty" );
			else
				System.out.println();
		}
	}
	
	public static boolean p( int k )
	{
		for( int i = 2 ; i * i <= k ; i++ )
			if( k % i == 0 )
				return false;
		return true;
	}
}