//03- Basic Input/Output

#include <iostream>
using namespace std; //no need std:: anymore

int main(){
	int i1, i2;
	cout << "Enter two numbers: ";
	cin >> i1 >> i2; //seperated by space or enter
	cout << "You've entered " << i1 << " and " << i2 << "." << endl;
	return 0;
}
