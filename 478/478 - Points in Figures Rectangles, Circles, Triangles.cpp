#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef struct {
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

double HL(double x1, double y1, double x2, double y2, double x3, double y3) {
	double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	double b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	double c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	double x = (a + b + c) / 2;

	return sqrt(x * (x - a) * (x - b) * (x - c));
}

bool t(Shape s, double x, double y) {
	double first = HL(s.v[0], s.v[1], s.v[2], s.v[3], x, y);
	double second = HL(s.v[0], s.v[1], x, y, s.v[4], s.v[5]);
	double third = HL(x, y, s.v[2], s.v[3], s.v[4], s.v[5]);
	if(first == 0 || second == 0 || third == 0)
		return false;

	if(fabs(HL(s.v[0], s.v[1], s.v[2], s.v[3], s.v[4], s.v[5]) - (first + second + third)) < 1e-6)
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
			if((vi->t == 'r' && r(*vi, x, y)) || (vi->t == 'c' && c(*vi, x, y)) || (vi->t == 't' && t(*vi, x, y))) {
				cout << "Point " << counter << " is contained in figure " << vi->index << endl;
				flag = false;
			}
		
		if(flag)
			cout << "Point " << counter << " is not contained in any figure" << endl;
	}

	return 0;
}