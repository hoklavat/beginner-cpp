//19-Pointer(Parameter)
//value of pointer parameter can be changed in function.

#include <iostream>
#include <vector>
using namespace std;

void DoubleInt(int *n); //pointer input
void DoubleVec(vector<int> *v);
void DoubleArr(int *a, int end);
int *CreateArray(size_t s); //pointer output

int main(){
	int n1{10};
	int *p1{&n1};
	int *p2{nullptr}; //points to nowhere
	vector<int> v1{1, 2, 3, 4, 5};
	int a1[5]{10, 20, 30, 40, 50};
	
	cout << "n1=" << n1 << endl;
	DoubleInt(&n1);
	cout << "DoubleInt(&n1), n1=" << n1 << endl;
	DoubleInt(p1);
	cout << "DoubleInt(p1), n1=" << n1 << endl;	
	
	cout << endl << "v1: ";
	DoubleVec(&v1);
	cout << endl;
	
	cout << endl << "a1: ";
	DoubleArr(a1, 10);
	
	p2 = CreateArray(5);
	for(size_t i{0}; i < 5; i++)
		cout << p2[i] << " ";
	delete [] p2;		
	cout << endl;
	
	return 0;
}

void DoubleInt(int *n){
	*n *= 2;
}

void DoubleVec(vector<int> *v){
	for(auto n: *v){
		n *= 2;
		cout << n << " ";
	}
}

void DoubleArr(int *a, int end){
	while(*a != end)
		cout << 2 * (*a++) << " ";
}

int *CreateArray(size_t s){
	int *p{new int[s]};
	for(size_t i{0}; i < s; i++)
		*(p + i) = i * 10;
	return p;
}
