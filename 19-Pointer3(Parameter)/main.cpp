//19- Pointer (Parameter)

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
	int a1[5]{6, 7, 8, 9, 10};
	
	cout << "n1: " << n1 << endl;
	DoubleInt(&n1);
	cout << "n1: " << n1 << endl;
	DoubleInt(p1);
	cout << "n1: " << n1 << endl;
	
	DoubleVec(&v1);
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
	cout << endl;
}

void DoubleArr(int *a, int end){
	while(*a != end)
		cout << 2 * (*a++) << " ";
	cout << endl;
}

int *CreateArray(size_t s){
	int *p{new int[s]};
	for(size_t i{0}; i < s; i++)
		*(p + i) = i * 10;
	return p;
}
