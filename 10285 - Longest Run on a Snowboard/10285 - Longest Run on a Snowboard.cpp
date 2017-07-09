#include <iostream>
#include <cstring>
using namespace std;

int base[105][105];
int longestPath, rows, columns;

void trace(int x, int y, int pathCounter) {	
	if(x > 0 && base[x-1][y] != -1 && base[x-1][y] < base[x][y]) {
		int temp = base[x][y];
		base[x][y] = -1;
		pathCounter++;
		if(pathCounter > longestPath)
			longestPath = pathCounter;
		trace(x - 1, y, pathCounter);
		pathCounter--;
		base[x][y] = temp;
	}
	if(x < rows - 1 && base[x+1][y] != -1 && base[x+1][y] < base[x][y]) {
		int temp = base[x][y];
		base[x][y] = -1;
		pathCounter++;
		if(pathCounter > longestPath)
			longestPath = pathCounter;
		trace(x + 1, y, pathCounter);
		pathCounter--;
		base[x][y] = temp;
	}
	if(y > 0 && base[x][y-1] != -1 && base[x][y-1] < base[x][y]) {
		int temp = base[x][y];
		base[x][y] = -1;
		pathCounter++;
		if(pathCounter > longestPath)
			longestPath = pathCounter;
		trace(x, y - 1, pathCounter);
		pathCounter--;
		base[x][y] = temp;
	}
	if(y < columns - 1  && base[x][y+1] != -1 && base[x][y+1] < base[x][y]) {
		int temp = base[x][y];
		base[x][y] = -1;
		pathCounter++;
		if(pathCounter > longestPath)
			longestPath = pathCounter;
		trace(x, y + 1, pathCounter);
		pathCounter--;
		base[x][y] = temp;
	}
}

int main(int argc, char *argv[]) {
	int cases = 0;
	
	cin >> cases;
	while(cases--) {
		string name = "";
		
		cin >> name >> rows >> columns;
		
		memset(base, -1, sizeof(base));
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				cin >> base[i][j];
				
		longestPath = 0;
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				trace(i, j, 1);
				
		cout << name << ": " << longestPath << endl;
	}
	
	return 0;
}
