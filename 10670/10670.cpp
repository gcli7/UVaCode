#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void ) {
	// cases : 共有幾筆測資, counter : 目前是第幾筆測資
	long cases = 0, counter = 0;
	scanf( "%ld", &cases );
	while( ++counter <= cases ) {
		// N : starting workload, M :  target workload, L : the number of work reduction agencies
		long n = 0, m = 0, l = 0;
		scanf( "%ld %ld %ld", &n, &m, &l );
		getchar();
		// agencies : every agency's name, temp : 暫存每個agency輸入
		char agencies[105][20] = {0}, temp[99] = {0};
		// cost: 需要付多少錢給相同index的agency
		long cost[105] = {0};

		long i = 0, j = 0, index = 0, tempIndex = 0;
		for( i = 0 ; i < l ; i++ ) {
			// 讀取第n間agency
			gets( temp );
			// 找出 : 的index, : 前就是agency的名字
			for( tempIndex = 0 ; temp[tempIndex] != ':' ; tempIndex++ );
			// 將temp裡的agency名字複製到agencies
			for( index = 0 ; index < tempIndex ; index++ )
				agencies[i][index] = temp[index];

			// 前兩個就是字面上的意思, jobs : 總工作量
			long costOfOneJob = 0, costOfHalfJob = 0, jobs = n;
			// 將字串轉成數字
			costOfOneJob = atoi( &temp[tempIndex+1] );
			// 找出 , 的index , 後就是costOfHalfJob
			for( ; temp[tempIndex] != ',' ; tempIndex++ );
			costOfHalfJob = atoi( &temp[tempIndex+1] );

			// 還有需要完成工作量就執行while loop
			while( jobs > m ) {
				long half = 0;
				if( jobs % 2 == 0 )
					half = jobs / 2;
				else
					half = ( jobs / 2 ) + 1;

				if( jobs - half < m ) {
					cost[i] += ( jobs - m ) * costOfOneJob;
					break;
				}
				else {
					if( half * costOfOneJob < costOfHalfJob )
						cost[i] += half * costOfOneJob;
					else
						cost[i] += costOfHalfJob;
				}
				jobs -= half;
			}
		}

		// 用氣泡排序法按照價錢做排序
		for( i = l - 1 ; i >= 0 ; i-- )
			for( j = 0 ; j < i ; j++ )
				if( cost[j] > cost[j+1] ) {
					index = cost[j];
					cost[j] = cost[j+1];
					cost[j+1] = index;

					strcpy( temp, &agencies[j][0] );
					strcpy( &agencies[j][0], &agencies[j+1][0] );
					strcpy( &agencies[j+1][0], temp );
				}

		// 用氣泡排序法按照agencies做排序
		for( i = l - 1 ; i >= 0 ; i-- )
			for( j = 0 ; j < i ; j++ )
				if( cost[j] == cost[j+1] && strcmp( &agencies[j][0], &agencies[j+1][0] ) > 0 ) {
					index = cost[j];
					cost[j] = cost[j+1];
					cost[j+1] = index;

					strcpy( temp, &agencies[j][0] );
					strcpy( &agencies[j][0], &agencies[j+1][0] );
					strcpy( &agencies[j+1][0], temp );
				}

		// 輸出要求的格式
		printf( "Case %ld\n", counter );
		for( i = 0 ; i < l ; i++ )
			printf( "%s %ld\n", &agencies[i][0], cost[i] );

	}

	return 0;
}
