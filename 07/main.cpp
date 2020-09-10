//07- Operators

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n1{10};
	int n2{0};
	bool n3{};
	double n4{1.234567};	
	
	cout << "5 / 10 = " << 5 / 10 << endl;
	cout << "5.0 / 10.0 = " << 5.0 / 10.0 << endl;
	cout << fixed << setprecision(2); //number of digits after point
	cout << "1.234567: " << n4 << endl;
	cout << "++n1 = " << ++n1 << endl;
	cout << "n1++ = " << n1++ << endl;
	cout << "n1 = " << n1 << endl;
	n2 = n1++;
	cout << "n2 = " << n2 << endl;
	
	cout << boolalpha; //true = 1, false = 0
	//cout << noboolalpha;
	cout << "n3 = " << n3 << endl;
	n3 = (100 == 50 + 50); //does 100 equal to 50 + 50? true
	cout << "(100 == 50 + 50) = " << n3 << endl;
	return 0;
}
