//13-FunctionOverloading

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//overloading: same funtion name, different types of input, same type of return.
void Display(int=100); //integer overload
void Display(double); //double overload
void Display(string); //string overload
void Display(vector<int>); //vector overload

int main(){
	Display(); //default parameter 100
	Display(10);
	Display(10.45);
	Display("Boris");
	Display(vector<int>{10, 20, 30, 40, 50});
	return 0;
}

void Display(int n1){
	cout << "Integer: " << n1 << endl;
}

void Display(double n1){
	cout << "Double: " << n1 << endl;
}

void Display(string s1){
	cout << "String: " << s1 << endl;
}

void Display(vector<int> v1){
	cout << "Vector: ";
	for(int i: v1)
		cout << i << " ";
	cout << endl;
}