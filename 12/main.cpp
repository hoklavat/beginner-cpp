//12- Default Arguments

#include <iostream>
using namespace std;

void Function1(int n1 = 1, int n2 = 2); //function prototype with default arguments

int main(){
	Function1();
	Function1(3);
	Function1(3, 5);	
	return 0;
}

void Function1(int n1, int n2){
	cout << "n1 = " << n1 << ", n2 = " << n2 << endl;
	return;
}