//16- Recursion

#include <iostream>
using namespace std;

int Factorial(int);
int Fibonacci(int);

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
	if(n <= 1) return n;
	return Fibonacci(n - 1) * Fibonacci(n - 2);
}