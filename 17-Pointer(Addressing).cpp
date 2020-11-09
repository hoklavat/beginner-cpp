//17-Pointer(Addressing)
//pointer: a variable that holds the address of another variable.
//n: value of variable
//*p: value at address pointed by pointer
//&n: address of variable
//p: address pointed by pointer

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n1{100};
	int n2{200};
	int *p{&n1}; //pointer p holds the address of variable n1
	vector<string> v{"Ali", "Burhan", "Cemal"};
	vector<string> *vp{&v}; //pointer vp holds the address of the first element in v
	
	cout << "n1: " << n1 << endl; //value of n1
	cout << "&n1: " << &n1 << endl; //address of n1
	cout << "*p: " << *p << endl; //value of n1
	cout << "p: " << p << endl; //address of n1
	
	p = &n2; //dereference: point to another address.
	cout << endl << "n2: " << n2 << endl; //value of n2
	cout << "&n2: " << &n2 << endl; //address of n2
	cout << "*p: " << *p << endl; //value of n2
	cout << "p: " << p << endl; //address of n2
	
	cout << endl << "(*vp).at(0): " << (*vp).at(0) << endl;
	for(auto s: *vp)
		cout << s << " ";
	cout << endl;
	
	//indirect addressing with pointer operations.
	int *p2;
	p2 = new int[5]; //allocate space on heap. p2 holds the starting address of array.
	cout << endl << "Pointer operations:" << endl;
	for(int i = 0; i < 5; i++){
		*(p2 + i) = i + 15; //increment address by 1 integer-size which is 4-byte. not 1-byte.
		cout << "Address: " << (p2 + i) << " Value: " << *(p2 + i) << endl;
	}
	delete [] p2; //free allocated space.
	
	return 0;
}