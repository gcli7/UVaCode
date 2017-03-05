#include<stdio.h>

int main()
{
	long test, Qtest, a[1005] = {0}, b[26] = {0}, i, j, count = 1, output;
	while(scanf("%ld", &test) != EOF && test != 0){
		
		for(i = 0; i < test; i++){
			scanf("%ld", &a[i]);
		}
		
		scanf("%ld", &Qtest);
		for(i = 0; i < Qtest; i++){
			scanf("%ld", &b[i]);
		}
		
		printf("Case %ld:\n", count);
		
		long tmp, k, min = a[0] + a[1];
		for(k = 0; k < Qtest; k++){
			for(i = 0; i < test; i++){ 
				for(j = 0; j < test; j++){
					if(i == j)
						continue;
					tmp = a[i] + a[j] - b[k];
					if( tmp < 0 )
						tmp = 0 - tmp;
					if( min - b[k] < 0) {
						if( tmp < 0 - ( min - b[k] ) )
							min = a[i] + a[j];
					}
					else {
						if( tmp < min - b[k] )
							min = a[i] + a[j];
					}
						
				}
			}
			printf("Closest sum to %ld is %ld.\n", b[k], min);
		}
		count++;
	}
	
	return 0;
}
