//18-Pointer(Constant)

#include <iostream>
using namespace std;

int main()
{
	int n1{10};
	int n2{20};
	const int *p1{&n1}; //pointer to constant, mutable address, immutable value
	int *const p2{&n1}; //constant pointer, immutable address, mutable value
	const int *const p3{&n1}; //constant pointer to constant, immutable address, immutable value
	
	cout << "n1 = *p1 = " << *p1 << endl;
	cout << "&n1 = p1 = " << p1 << endl;
	//*p = 30; //error, constant value cannot be changed.
	p1 = &n2; //address can be changed.
	cout << endl << "n2 = *p1 = " << *p1 << endl;
	cout << "&n2 = p1 = " << p1 << endl;
	
	cout << endl << "n1 = *p2 = " << *p2 << endl;
	//p2 = &n2; //error, constant address cannot be changed.
	*p2 = 30; //value can be changed.
	cout << "n1 = *p2 = " << *p2 << endl;
	
	cout << endl << "n1 = *p3 = " << *p3 << endl;
	cout << "&n1 = p3 = " << p3 << endl;
	//*p3 = 30; //error, constant value cannot be changed. 
	//p3 = &n2; //error, constant address cannot be changed.

	return 0;
}