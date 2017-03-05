#include <stdio.h>

int main( void )
{
	int cases, month, day;
	
	scanf("%d", &cases);
	while( cases-- ) {
		scanf("%d %d", &month, &day);
		switch( month ) {
			case 12: day += 30;
			case 11: day += 31;
			case 10: day += 30;
			case 9: day += 31;
			case 8: day += 31;
			case 7: day += 30;
			case 6: day += 31;
			case 5: day += 30;
			case 4: day += 31;
			case 3: day += 28;
			case 2: day += 31;
			default: break;
		}
		
		switch( day % 7 ) {
			case 0: printf("Friday\n"); break;
			case 1: printf("Saturday\n"); break;
			case 2: printf("Sunday\n"); break;
			case 3: printf("Monday\n"); break;
			case 4: printf("Tuesday\n"); break;
			case 5: printf("Wednesday\n"); break;
			case 6: printf("Thursday\n"); break;
		}
	}
	
	return 0;
}
