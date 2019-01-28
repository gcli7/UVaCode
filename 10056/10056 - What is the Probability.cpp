#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){
	int cases = 0;
	
	cin >> cases;
	while(cases--) {
		int persons = 0, winPerson = 0;
		double sum = 0, p = 0, roundSum = 0, tempSum = 0;
		
		cin >> persons >> p >> winPerson;
		
		tempSum = p;
		for(int i = 1; i < winPerson; i++)
			tempSum *= 1 - p;
		sum = tempSum;
		
		roundSum = pow((1 - p), persons);
		
		while((tempSum *= roundSum) >= 0.000000001)
			sum += tempSum;
			
		printf("%.4lf\n", sum);
	}
	
	return 0;
}
