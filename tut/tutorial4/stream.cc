#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main(int argv, char* argc[]) { 
	string file = "";
	int begin, end, incr;
	if ( argv != 2 ){
		cerr << "This program expects the argument of the name of a file to save to." << endl;
		return 1;
	} else {
		file = argc[1];
		cerr << "Saving to: " << file << endl;
	}
	cerr << "Begin #: ";
	string temp;
	while (cin >> temp){
		stringstream ss(temp);
		if ( ss >> begin ) break;
		cerr << "Please enter a number: " << endl;
	}
	cerr << "End #: ";
	while (cin >> temp){
		stringstream ss(temp);
		if ( ss >> end ) break;
		cerr << "Please enter a number: " << endl;
	}
	cerr << "Increment #: ";
	while (cin >> temp){
		stringstream ss(temp);
		if ( ss >> incr ) break;
		cerr << "Please enter a number: " << endl;
	}
	if ( ! cin.fail() ){
		int cur = begin;
		ofstream f(file.c_str());
		stringstream ss;
		while ( cur < end ){
			f << cur << endl;
			ss << cur << endl;
			cout << cur << endl;
			cur += incr;
		}
	} else {
		cerr << endl << "cin failed at some point. Program termianted." << endl;
	}
}
