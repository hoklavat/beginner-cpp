//13- Function Overloading

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Display(int=100);
void Display(double);
void Display(string);
void Display(vector<int>);

int main(){
	Display();
	Display(10);
	Display(10.45);
	Display("Boris");
	Display(vector<int>{10, 20, 30, 40, 50});
	return 0;
}

void Display(int n1){
	cout << "Integer : " << n1 << endl;
}

void Display(double n1){
	cout << "Double : " << n1 << endl;
}

void Display(string s1){
	cout << "String : " << s1 << endl;
}

void Display(vector<int> v1){
	for(int i: v1)
		cout << i << " ";
	cout << endl;
}