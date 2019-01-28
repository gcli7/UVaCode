#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	map<string, char> base;
	map<string, char>::iterator mi;
	
	base[".-"] = 'A';	base["-..."] = 'B';	base["-.-."] = 'C';	base["-.."] = 'D';
	base["."] = 'E';	base["..-."] = 'F';	base["--."] = 'G';	base["...."] = 'H';
	base[".."] = 'I';	base[".---"] = 'J';	base["-.-"] = 'K';	base[".-.."] = 'L';
	base["--"] = 'M';	base["-."] = 'N';	base["---"] = 'O';	base[".--."] = 'P';
	base["--.-"] = 'Q';	base[".-."] = 'R';	base["..."] = 'S';	base["-"] = 'T';
	base["..-"] = 'U';	base["...-"] = 'V';	base[".--"] = 'W';	base["-..-"] = 'X';
	base["-.--"] = 'Y';	base["--.."] = 'Z';	base["-----"] = '0';	base[".----"] = '1';
	base["..---"] = '2';	base["...--"] = '3';	base["....-"] = '4';	base["....."] = '5';
	base["-...."] = '6';	base["--..."] = '7';	base["---.."] = '8';	base["----."] = '9';
	base[".-.-.-"] = '.';	base["--..--"] = ',';	base["..--.."] = '?';	base[".----."] = '\'';
	base["-.-.--"] = '!';	base["-..-."] = '/';	base["-.--."] = '(';	base["-.--.-"] = ')';
	base[".-..."] = '&';	base["---..."] = ':';	base["-.-.-."] = ';';	base["-...-"] = '=';
	base[".-.-."] = '+';	base["-....-"] = '-';	base["..--.-"] = '_';	base[".-..-."] = '"';
	base[".--.-."] = '@';	base["*"] = ' ';
	
	
	int cases = 0, counter = 0;
	string input;
	
	cin >> cases;
	getline(cin, input);
	while(cases--) {
		if(counter)
			cout << endl;
		cout << "Message #" << ++counter << endl;
		
		
		stringstream ss;
		bool flag = false;
		
		getline(cin, input);
		for(int i = 0; i < input.length(); i++)
			if(input[i] == ' ' && input[i+1] == ' ') {
				input[i+1] = '*';
				input = input.substr(0, i + 2) + " " + input.substr(i + 2);
			}
			
		ss << input;
		while(ss >> input)
			cout << base[input];
		cout << endl;
	}
	
	return 0;
}
