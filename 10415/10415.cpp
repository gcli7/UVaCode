#include <stdio.h>
#include <string.h>

int main( void )
{
	const char c[] = { 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 }, d[] = { 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0 },
			   e[] = { 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0 }, f[] = { 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
		 	   g[] = { 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 }, a[] = { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		 	   b[] = { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, C[] = { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
		 	   D[] = { 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0 }, E[] = { 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0 },
		 	   F[] = { 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 }, G[] = { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
		 	   A[] = { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }, B[] = { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
				start[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int cases;
	
	scanf("%d", &cases);
	getchar();
	while( cases-- ) {		
		char instruction[201] = {0}, output[11] = {0};
		const char *last_ptr, *next_ptr;
		int l, i, j, s;
		
		instruction[0] = getchar();
		if( instruction[0] == '\n' ) {
			printf("0 0 0 0 0 0 0 0 0 0\n");
			continue;
		}
		gets( &instruction[1] );
		l = strlen( instruction );
		s = sizeof( c[0] );
		
		last_ptr = start;
		for( i = 0 ; i < l ; i++ ) {
			switch( instruction[i] ) {
				case 'c': next_ptr = c;	break;
				case 'd': next_ptr = d;	break;
				case 'e': next_ptr = e;	break;
				case 'f': next_ptr = f;	break;
				case 'g': next_ptr = g;	break;
				case 'a': next_ptr = a;	break;
				case 'b': next_ptr = b;	break;
				case 'C': next_ptr = C;	break;
				case 'D': next_ptr = D;	break;
				case 'E': next_ptr = E;	break;
				case 'F': next_ptr = F;	break;
				case 'G': next_ptr = G;	break;
				case 'A': next_ptr = A;	break;
				case 'B': next_ptr = B;	break;
			}
			for( j = 1 ; j <= 10 ; j++ ) {
				last_ptr += s;
				next_ptr += s;
				if( *last_ptr == 0 && *next_ptr == 1 )
					output[j]++;
			}
			
			last_ptr = next_ptr - 10 * s;
		}
		
		for( i = 1 ; i < 10 ; i++ )
			printf("%d ", output[i]);
		printf("%d\n", output[10]);
	}
	
	return 0;
}
