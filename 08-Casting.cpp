//08-Casting
//converting one type to another. example: floating point to integer.

#include <iostream>
using namespace std;

int main(){
	int n1{100};
	int n2{8};
	double n3{0};
	
	n3 = n1/n2;
	cout << "n1/n2 = " << n3 << endl;
	//n3 = (double)n1 / n2 //no error checking. not recommended.
	n3 = static_cast<double> (n1)/n2; //throws exception on invalid conditions.
	cout << "static_cast<double> n1/n2 = " << n3 << endl;	
	return 0;
}