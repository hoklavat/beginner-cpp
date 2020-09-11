//05- Primitive Types

#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main(){
	//sizeof(type_name or variable_name)
	cout << "sizeof(char): " << sizeof(char) << endl;
	cout << "sizeof(char16_t): " << sizeof(char16_t) << endl;
	cout << "sizeof(char32_t): " << sizeof(char32_t) << endl;
	cout << "sizeof(wchar_t): " << sizeof(wchar_t) << endl;
	cout << "sizeof(short int): " << sizeof(short int) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;	
	cout << "sizeof(long): " << sizeof(long) << endl;
	cout << "sizeof(long long): " << sizeof(long long) << endl;
	cout << "sizeof(float): " << sizeof(float) << endl;
	cout << "sizeof(double): " << sizeof(double) << endl;
	cout << "sizeof(long double): " << sizeof(long double) << endl;
	cout << "sizeof(bool): " << sizeof(bool) << endl;
	cout << "char min/max: " << CHAR_MIN << "/" << CHAR_MAX << endl;
	cout << "short min/max: " << SHRT_MIN << "/" << SHRT_MAX << endl;
	cout << "int min/max: " << INT_MIN << "/" << INT_MAX << endl;
	cout << "long long min/max: " << LLONG_MIN << "/" << LLONG_MAX << endl;
	cout << "float min/max: " << FLT_MIN << "/" << FLT_MAX << endl;
	cout << "double min/max: " << DBL_MIN << "/" << DBL_MAX << endl;
	cout << "long double min/max: " << LDBL_MIN << "/" << LDBL_MAX << endl;
	return 0;
}
