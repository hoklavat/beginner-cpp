//39-Exception Handling(UserDefined)

#include <iostream>
using namespace std;

class DivideByZeroException{};
class NegativeValueException{};

double Divide(int x, int y){
	if(y == 0) throw DivideByZeroException();
	if(x < 0 || y < 0) throw NegativeValueException();
	return static_cast<double>(x)/y;
}

int main(){
	double a{0};
	double b{10}; 
	double c{0}; //test with c{-10} also.
	
	try{
		a = Divide(b, c);
	}
	catch(DivideByZeroException &ex){
		cerr << "Exception: Divide by Zero." << endl;
	}
	catch(NegativeValueException &ex){
		cerr << "Exception: Negative Value." << endl;
	}		
	cout << endl;
	
	return 0;
}