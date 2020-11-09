//41-Stream(Manipulators)

//noboolalpha: display boolean as integer (0, 1).
//boolalpha: display boolean as string(false, true).
//showbase: show number base.
//showpos: show positive sign.
//dec: decimal number. base=10.
//hex: hexadecimal number. base=16.
//oct: octal number. base=8.
//fixed: show decimal digits.
//setprecision: set total number of decimal digits.
//showpoint: show decimal point even if number doesn't have digit after point. fill with zeroes until precision fulfilled.
//setw: set field width in output operations. left, right justification.
//resetiosflags(): reset manipulator flag to its default value. cout.unsetf()


#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	cout << "(noboolalpha) -> (10 == 10): " << (10 == 10) << endl; //default: noboolalpha
	
	cout << boolalpha;
	cout << "(boolalpha) -> (10 == 10): " << (10 == 10) << endl;
	cout << endl;
	
	cout << showpos << dec; //positive sign, decimal number.
	cout << "decimal number with positive sign: " << 255 << endl;
	
	cout << hex << uppercase << showbase; //hexadecimal number with uppercase letters, show base.
	cout << "hexadecimal number with upper case letter: " << 255 << endl;
	
	cout << oct;
	cout << "octal number: "  << oct << 255 << endl;
	cout << endl;
	
	//cout.setf(ios::boolalpha)
	//cout.setf(ios::showpos)
	//cout.setf(ios::showbase)
	//cout.setf(ios::uppercase)
	//cout.setf(ios::showbase)
	cout << resetiosflags(ios::boolalpha);	//default: noboolalpha
	cout << resetiosflags(ios::showpos);	//default: noshowpos
	cout << resetiosflags(ios::showbase);	//default: noshowbase
	cout << resetiosflags(ios::uppercase);	//default: lowercase
	cout << resetiosflags(ios::basefield);	//default: noshowbase
	
	double a = 12345.12345;
	double b = 12345;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	cout << showpoint;
	cout << "(showpoint) a = " << a << endl;
	cout << "(showpoint) b = " << b << endl;
	
	cout << fixed;
	cout << "(showpoint, fixed) -> a = " << fixed << a << endl; //default precision is 6.
	cout << "(showpoint, fixed) -> b = " << fixed << b << endl; //default precision is 6.
	
	cout << setprecision(10);
	cout << "(showpoint, fixed, setprecision) -> a = " << a << endl; //fill rest with 0.
	cout << "(showpoint, fixed, setprecision) -> b = " << b << endl; //fill rest with 0.
	
	cout << scientific;
	cout << "(showpoint, fixed, setprecision, scientific) -> a = " << a << endl; //fill rest with 0.
	cout << "(showpoint, fixed, setprecision, scientific) -> b = " << b << endl; //fill rest with 0.
	
	cout.unsetf(ios::scientific| ios::fixed | ios::showpoint);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;
	
	//Output Manipulation
	cout << 12345.6789 << "1234567890" << endl;
	cout << setw(10) << 12345.12345 << setw(10) << "1234567890" << endl;
	cout << setw(15) << 12345.12345 << setw(15) << "1234567890" << endl; //words are 10 characters, width is 15, so 15-10=5 spaces on left.
	
	cout << left; //default is right.
	cout << setw(15) << 12345.12345 << setw(15) << "1234567890" << endl;
	
	cout << setfill('*'); //fill with * instead of spaces.
	cout << setw(15) << 12345.12345 << setw(15) << "1234567890" << endl;
	
	return 0;
}