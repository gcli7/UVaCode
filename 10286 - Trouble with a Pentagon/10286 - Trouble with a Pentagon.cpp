#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
	double side = 0, output = 0;
	
	while(cin >> side) {
		output = side * cos(9 * M_PI / 180);
		side = side * sin(9 * M_PI / 180);
		output += side * tan(27 * M_PI / 180);
		
		cout << fixed << setprecision(10) <<output << endl;
	}
	
	return 0;
}
