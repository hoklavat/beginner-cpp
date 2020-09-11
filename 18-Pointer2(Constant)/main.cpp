//18- Pointer 2 (Constant)

#include <iostream>
using namespace std;

int main()
{
	int n1{10};
	int n2{20};
	const int *p1{&n1}; //pointer to constant, mutable address, immutable value
	int *const p2{&n1}; //constant pointer, immutable address, mutable value
	const int *const p3{&n1}; //constant pointer to constant, immutable address, immutable value
	
	cout << "*p1: " << *p1 << endl;
	//*p = 30; //error
	p1 = &n2;
	cout << "*p1: " << *p1 << endl;
	
	cout << "*p2: " << *p2 << endl;
	//p2 = &n2; //error
	*p2 = 30;
	cout << "*p2: " << *p2 << endl;
	
	cout << "*p3: " << *p3 << endl;
	//*p3 = 30; //error
	//p3 = &n2; //error

	return 0;
}
