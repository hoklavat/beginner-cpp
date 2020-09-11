//43- Stream (String Stream)

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	string s1{"Baris 123 123.456"};
	string s2;
	int i1;
	double d1;
	istringstream is1{s1};
	ostringstream os1{};
	is1 >> s2 >> i1 >> d1;
	cout << s2 << ", " << i1 << ", " << d1 << endl;
	os1 << s2 << "\\" << i1 << "\\" << d1 << endl;
	cout << os1.str();
	
	//Input Validation
	cout << "Enter an integer: ";
	cin >> s1;
	istringstream is2{s1};
	if(is2 >> i1)
		cout << "You've entered " << i1 << "." << endl;
	else
		cout << "You've not entered an integer." << endl;
	//cin.ignore(numeric_limits<stream_size>::max(), '\n');	
	cout << endl;

	return 0;
}
