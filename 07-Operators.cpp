//07-Operators

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n1{10};
	double n2{1.234567};
	bool n3{};
	
	cout << "5/10 = " << 5/10 << endl; //result is integer
	cout << "5.0/10.0 = " << 5.0/10.0 << endl; //result is floating-point
	
	cout << fixed << setprecision(2); //number of digits after point
	cout << endl << "1.234567: " << n2 << endl;
	
	cout << endl << "n1 = " << n1 << " -> " << "++n1 = " << ++n1 << endl; //increment then process
	cout << "n1 = " << n1 << " -> " << "n1++ = " << n1++ << " -> " << "n1 = " << n1 << endl; //process then increment
	
	cout << boolalpha; //1->true, 0->false
	//cout << noboolalpha; //true->1, false->0
	cout << endl << "n3 = " << n3 << endl;
	n3 = (100 == 50 + 50); //does 100 equal to 50 + 50? true
	cout << "(100 == 50 + 50) = " << n3 << endl;
	
	return 0;
}
