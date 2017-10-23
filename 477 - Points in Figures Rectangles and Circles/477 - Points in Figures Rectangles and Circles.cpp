#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef struct shape {
	char t;
	double v[6];
	int index;
} Shape;

bool r(Shape s, double x, double y) {
	if(x < s.v[2] && x > s.v[0] && y < s.v[1] && y > s.v[3])
		return true;
	return false;
}

bool c(Shape s, double x, double y) {
	if(sqrt((x - s.v[0]) * (x - s.v[0]) + (y - s.v[1]) * (y - s.v[1])) < s.v[2])
		return true;
	return false;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<Shape> base;
	Shape temp;
	int counter = 0;

	while(cin >> temp.t && temp.t != '*') {
		if(temp.t == 'r')
			cin >> temp.v[0] >> temp.v[1] >> temp.v[2] >> temp.v[3];
		else if(temp.t == 'c')
			cin >> temp.v[0] >> temp.v[1] >> temp.v[2];
		else
			cin >> temp.v[0] >> temp.v[1] >> temp.v[2] >> temp.v[3] >> temp.v[4] >> temp.v[5];

		temp.index = ++counter;
		base.push_back(temp);
	}

	double x = 0.0, y = 0.0;
	counter = 0;

	while(cin >> x >> y && !(x == 9999.9 && y == 9999.9)) {
		counter++;
		bool flag = true;

		for(vector<Shape>::iterator vi = base.begin(); vi != base.end(); vi++)
			if((vi->t == 'r' && r(*vi, x, y)) || (vi->t == 'c' && c(*vi, x, y))) {
				cout << "Point " << counter << " is contained in figure " << vi->index << "\n";
				flag = false;
			}
		
		if(flag)
			cout << "Point " << counter << " is not contained in any figure\n";
	}

	return 0;
}