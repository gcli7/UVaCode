#include <iostream>
#include <iomanip>
using namespace std;

const double rate[][3] = {{0.10, 0.06, 0.02}, {0.25, 0.15, 0.05}, {0.53, 0.33, 0.13}, {0.87, 0.47, 0.17}, {1.44, 0.80, 0.30}};

int main(int argc, char **argv) {
	string step = "";

	while(cin >> step && step != "#") {
		string number = "";
		int start_h = 0, start_m = 0, end_h = 0, end_m = 0;
		int Drate = 0, Erate = 0, Nrate = 0;

		cin >> number >> start_h >> start_m >> end_h >> end_m;
		start_m += start_h * 60;
		end_m += end_h * 60;

		do {
			start_m = (start_m + 1) % 1440;
			if(start_m > 480 && start_m <= 1080)
				Drate++;
			else if(start_m > 1080 && start_m <= 1320)
				Erate++;
			else
				Nrate++;
		}
		while(start_m != end_m);

		cout << setw(10) << number << setw(6) << Drate << setw(6) << Erate << setw(6) << Nrate << setw(3) << step << setw(8) << fixed << setprecision(2) << Drate * rate[step[0]-'A'][0] + Erate * rate[step[0]-'A'][1] + Nrate * rate[step[0]-'A'][2] << endl;
	}

	return 0;
}