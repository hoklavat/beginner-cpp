//43-Stream(StringStream)

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	istringstream si{"Ali 18 1.78"};
	ostringstream so{};
	
	string name;
	int age;
	double height;
	
	si >> name >> age >> height;
	cout << "Name: " << name << ", Age: " << age << ", Height: " << height << endl;
	
	so << name << "\\" << age << "\\" << height << endl;
	cout << so.str() << endl;	
	
	//Input Validation
	string s;
	int i;
	cout << "Enter an integer: ";
	
	//clear buffer befor taking new input.
	//cin.ignore(numeric_limits<stream_size>::max(), '\n');
	cin >> s;
	istringstream si2{s};
	
	if(si2 >> i) //is this a valid extraction?
		cout << "You entered " << i << "." << endl;
	else
		cout << "You didn't enter an integer." << endl;
		
	cout << endl;

	return 0;
}
