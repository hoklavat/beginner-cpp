//39- Exception Handling (User-Defined)

#include <iostream>
using namespace std;

class DivideByZeroException{};
class NegativeValueException{};

double Divide(int a, int b){
	if(b == 0) throw DivideByZeroException();
	if(a < 0 || b < 0) throw NegativeValueException();
	return static_cast<double>(a) / b;
}

int main(){
	int b{10}, c{0}; //test c{-10}
	
	try{
		cout << Divide(b, c) << endl;
	}
	catch(DivideByZeroException &ex){
		cerr << "Error: Divide by Zero." << endl;
	}
	catch(NegativeValueException &ex){
		cerr << "Error: Negative Value Exception." << endl;
	}
		
	cout << endl;
	return 0;
}

