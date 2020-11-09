//05-PrimitiveTypes

#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main(){
	cout << "sizeof(char): " << sizeof(char) << endl; //1-byte
	cout << "sizeof(char16_t): " << sizeof(char16_t) << endl; //2-bytes
	cout << "sizeof(char32_t): " << sizeof(char32_t) << endl; //4-bytes
	cout << "sizeof(wchar_t): " << sizeof(wchar_t) << endl; //2-bytes
	cout << "sizeof(short int): " << sizeof(short int) << endl; //2-bytes
	cout << "sizeof(int): " << sizeof(int) << endl; //4-bytes
	cout << "sizeof(long): " << sizeof(long) << endl; //4-bytes
	cout << "sizeof(long long): " << sizeof(long long) << endl; //8-bytes
	cout << "sizeof(float): " << sizeof(float) << endl; //4-bytes
	cout << "sizeof(double): " << sizeof(double) << endl; //8-bytes
	cout << "sizeof(long double): " << sizeof(long double) << endl; //12-bytes
	cout << "sizeof(bool): " << sizeof(bool) << endl; //1-byte
	cout << "char min/max: " << CHAR_MIN << "/" << CHAR_MAX << endl; //-128/127
	cout << "short min/max: " << SHRT_MIN << "/" << SHRT_MAX << endl; //-32768/32767
	cout << "int min/max: " << INT_MIN << "/" << INT_MAX << endl; //-2147483648/2147483647
	cout << "long long min/max: " << LLONG_MIN << "/" << LLONG_MAX << endl; //-9223372036854775808/9223372036854775807
	cout << "float min/max: " << FLT_MIN << "/" << FLT_MAX << endl; //1.17549e-038/3.40282e+038, e means exponent of 10. 2e-5 = 2 * 10^(-5)
	cout << "double min/max: " << DBL_MIN << "/" << DBL_MAX << endl; //2.22507e-308/1.79769e+308
	cout << "long double min/max: " << LDBL_MIN << "/" << LDBL_MAX << endl; //3.3621e-4932/1.18973e+4932
	
	return 0;
}