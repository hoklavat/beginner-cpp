//17- Pointer 1 (Addressing)

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n1{100};
	int n2{200};
	int *p{&n1}; //p points to address of n1	
	vector<string> v{"Baris", "Boris", "Bruce"};
	vector<string> *vp{&v};
	
	cout << "n1: " << n1 << endl;
	cout << "&n1: " << &n1 << endl;
	cout << "*p: " << *p << endl;
	cout << "p: " << p << endl;
	
	p = &n2; //dereference
	cout << "n2: " << n2 << endl;
	cout << "&n2: " << &n2 << endl;
	cout << "*p: " << *p << endl;
	cout << "p: " << p << endl;
	
	cout << "(*vp).at(0): " << (*vp).at(0) << endl;
	for(auto s: *vp)
		cout << s;
	cout << endl;
	
	int *p2;
	p2 = new int[5];
	for(int i = 0; i < 5; i++)
	{
		*(p2 + i) = i + 15;
		cout << "Address: " << (p2 + i) << " Value: " << *(p2 + i) << endl;
	}
	delete [] p2;	
	return 0;
}
