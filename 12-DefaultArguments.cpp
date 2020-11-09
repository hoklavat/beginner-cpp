//12-DefaultArguments

#include <iostream>
using namespace std;

void Function1(int n1 = 1, int n2 = 2); //function prototype with default arguments

int main(){
	Function1(); //n1=1, n2=2
	Function1(3); //n1=3, n2=2
	Function1(3, 5); //n1=3, n2=5
	return 0;
}

void Function1(int n1, int n2){
	cout << "n1 = " << n1 << ", n2 = " << n2 << endl;
	return;
}