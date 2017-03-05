import java.util.*;
import java.math.BigInteger;

public class Main
{	
	public static void main( String[] args )
	{
		Scanner sc = new Scanner( System.in );
		int cases = 0, farmers = 0;
		long size = 0, animals = 0, ef = 0, sum = 0;
		
		cases = sc.nextInt();
		while( cases-- > 0 ) {
			farmers = sc.nextInt();
			sum = 0;
			while( farmers-- > 0 ) {
				size = sc.nextLong();
				animals = sc.nextLong();
				ef = sc.nextLong();
				
				sum += size * ef;
			}
			
			System.out.println( sum );
		}
	}
}