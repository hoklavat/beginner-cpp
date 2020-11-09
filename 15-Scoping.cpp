//15-Scoping
//scope: code between open and closed brackets.
//if there are variables with same name in different scopes, variable in the inner most scope is considered first.

#include <iostream>
using namespace std;

int n1{1}; //global variable
void PrintGlobal();
void PrintStatic();

int main(){
	int n1{10}; //local variable of main function
	int n2{20};
	
	cout << "Main function variables: ";
	cout << "n1 = " << n1  << ", n2 = " << n2 << endl;
	
	//inner scope
	{
		int n2{30}; //inner scope has priority.
		cout << "Inner scope variables: ";
		cout << "n1 = " << n1  << ", n2 = " << n2 << endl; //n1 is 10 not 1. n2 is 30 not 20.
	}
	
	cout << "Global variable: ";
	PrintGlobal();
	
	cout << "Static variable: n1 = ";
	for(int i = 0; i < 10; i++)
		PrintStatic();
	cout << endl;
	
	return 0;
}

void PrintGlobal(){
	//int n1 = 40;
	cout << "n1 = " << n1 << endl; //global variable is 1.
}

void PrintStatic(){
	static int n1{0}; //static variable is hold in memory until program ends. after each function call last state is saved.
	cout << n1 << " ";
	n1++; //increment by one after each call. 0, 1, 2, 3, ...
}