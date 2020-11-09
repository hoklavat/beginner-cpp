//16-Recursion
//function call itself. kind of iteration.

#include <iostream>
using namespace std;

int Factorial(int); //1 * 2 * 3 * ... * n
int Fibonacci(int); //0, 1, (0+1)=1, (1+1)=2, (1+2)=3, (2+3)=5, (3+5)=8, ...

int main(){
	cout << "Factorial(8) = " << Factorial(8) << endl;
	cout << "Fibonacci(8) = " << Fibonacci(8) << endl;
	return 0;
}

int Factorial(int n){
	if(n == 0) return 1;
	return n * Factorial(n - 1);
}

int Fibonacci(int n){
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}