#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void ) {
	// cases : �@���X������, counter : �ثe�O�ĴX������
	long cases = 0, counter = 0;
	scanf( "%ld", &cases );
	while( ++counter <= cases ) {
		// N : starting workload, M :  target workload, L : the number of work reduction agencies
		long n = 0, m = 0, l = 0;
		scanf( "%ld %ld %ld", &n, &m, &l );
		getchar();
		// agencies : every agency's name, temp : �Ȧs�C��agency��J
		char agencies[105][20] = {0}, temp[99] = {0};
		// cost: �ݭn�I�h�ֿ����ۦPindex��agency
		long cost[105] = {0};

		long i = 0, j = 0, index = 0, tempIndex = 0;
		for( i = 0 ; i < l ; i++ ) {
			// Ū����n��agency
			gets( temp );
			// ��X : ��index, : �e�N�Oagency���W�r
			for( tempIndex = 0 ; temp[tempIndex] != ':' ; tempIndex++ );
			// �Ntemp�̪�agency�W�r�ƻs��agencies
			for( index = 0 ; index < tempIndex ; index++ )
				agencies[i][index] = temp[index];

			// �e��ӴN�O�r���W���N��, jobs : �`�u�@�q
			long costOfOneJob = 0, costOfHalfJob = 0, jobs = n;
			// �N�r���ন�Ʀr
			costOfOneJob = atoi( &temp[tempIndex+1] );
			// ��X , ��index , ��N�OcostOfHalfJob
			for( ; temp[tempIndex] != ',' ; tempIndex++ );
			costOfHalfJob = atoi( &temp[tempIndex+1] );

			// �٦��ݭn�����u�@�q�N����while loop
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

		// �ή�w�ƧǪk���ӻ������Ƨ�
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

		// �ή�w�ƧǪk����agencies���Ƨ�
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

		// ��X�n�D���榡
		printf( "Case %ld\n", counter );
		for( i = 0 ; i < l ; i++ )
			printf( "%s %ld\n", &agencies[i][0], cost[i] );

	}

	return 0;
}
