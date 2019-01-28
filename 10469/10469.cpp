#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	unsigned int base[32] = {0};
	
	base[0] = 1;
	for(int i = 1; i < 32; i++)
		base[i] = base[i-1] * 2;
	
	int a = 0, b = 0;
	
	while(cin >> a >> b) {
		int binary_a[32] = {0}, binary_b[32] = {0};
		
		for(int i = 31; a > 0; i--)
			if(a >= base[i]) {
				binary_a[i] = 1;
				a -= base[i];
			}
		for(int i = 31; b > 0; i--)
			if(b >= base[i]) {
				binary_b[i] = 1;
				b -= base[i];
			}
		
		int output = 0;
		for(int i = 0; i < 32; i++)
			if(binary_a[i] ^ binary_b[i])
				output += base[i];
				
		cout << output << endl;
	}
	
	return 0;
}
