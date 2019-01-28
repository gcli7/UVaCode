#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	double cows = 0.0, cars = 0.0, show = 0.0;
	
	while(cin >> cows >> cars >> show)
		cout << fixed << setprecision(5) << (cows / (cows + cars)) * (cars / (cows + cars - show - 1)) + (cars / (cows + cars)) * ((cars - 1) / (cows + cars - show - 1)) << endl;
	
	return 0;
}
