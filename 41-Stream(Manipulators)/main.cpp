//41- Stream (Manipulators)

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	//cout.setf(ios::boolalpha)
	//cout.setf(ios::showpos)
	//cout.setf(ios::showbase)
	//cout.setf(ios::uppercase)
	cout << (10 == 10) << endl; //default: noboolalpha
	cout << boolalpha;
	cout << (10 == 10) << endl;
	cout << endl;	
	
	cout << showpos << dec << 255 << endl; //default: noshowpos
	cout << showbase << uppercase << hex << 255 << endl; //default: noshowbase, nouppercase
	cout << showbase << oct << 255 << endl;
	cout << endl;
	
	cout << resetiosflags(ios::boolalpha);
	cout << resetiosflags(ios::basefield);
	cout << resetiosflags(ios::showpos);
	cout << resetiosflags(ios::showbase);
	cout << resetiosflags(ios::uppercase);
	
	cout << 1234.5678 << endl;
	cout << showpoint << 12.34 << endl;
	cout << 123456789.987654321 << endl;
	cout << setprecision(9) << 123456789.987654321 << endl;
	cout << setprecision(6) << fixed << 123456789.987654321 << endl;
	cout << setprecision(3) << scientific << showpos << 123456789.987654321 << endl;
	cout.unsetf(ios::scientific | ios::showpos | ios::fixed | ios::showpoint);
	cout << setprecision(6);
	//cout << resetiosflags(ios::floatfield);
	cout << 1234.5678 << endl;
	cout << endl;
	
	cout << 1234.5678 << "Hello" << endl;
	cout << setw(10) << 1234.5678 << "Hello" << endl;
	cout << setw(10) << 1234.5678 << setw(10) << "Hello" << endl;
	cout << left << setw(10) << 1234.5678 << setw(10) << "Hello" << endl; //default justify: right
	cout << setfill('-') << setw(10) << 1234.5678 << setfill('*') << setw(10) << "Hello" << endl;	
	return 0;
}
