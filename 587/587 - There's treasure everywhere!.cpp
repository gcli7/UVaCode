#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const double N = sqrt(0.5);
	string input = "";
	int counter = 0;

	while(getline(cin, input) && input != "END") {
		double x = 0.0, y = 0.0, l = 0.0;
		string dir = "";
		stringstream ss(input.substr(0, input.length() - 1));

		while(getline(ss, input, ',')) {
			if(input[input.length() - 2] >= '0' && input[input.length() - 2] <= '9') {
				l = atoi(input.substr(0, input.length() - 1).c_str());
				dir = input[input.length() - 1];
			}
			else {
				l = atoi(input.substr(0, input.length() - 2).c_str());
				dir = input.substr(input.length() - 2, 2);
			}

			if(dir == "N")
				y += l;
			else if(dir == "E")
				x += l;
			else if(dir == "S")
				y -= l;
			else if(dir == "W")
				x -= l;
			else if(dir == "NW") {
				x -= l * N;
				y += l * N;
			}
			else if(dir == "NE") {
				x += l * N;
				y += l * N;
			}
			else if(dir == "SW") {
				x -= l * N;
				y -= l * N;
			}
			else if(dir == "SE") {
				x += l * N;
				y -= l * N;
			}
		}

		cout << "Map #" << ++counter << "\n";
		cout << fixed << setprecision(3) << "The treasure is located at (" << x << "," << y << ").\n";
		cout << "The distance to the treasure is " << sqrt(x * x + y * y) << ".\n\n";
	}

	return 0;
}