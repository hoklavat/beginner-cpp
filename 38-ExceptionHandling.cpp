//38-ExceptionHandling

#include <iostream>
using namespace std;

//divide x by y. if y is 0 or numbers are negative throw exception.
double Divide(int x, int y){
	if(y == 0) throw 0; //integer code
	if(x < 0 || y < 0) throw string{"Negative Value."}; //string code
	return static_cast<double>(x)/y;
}

int main(){
	double a{0};
	double b{-10}; 
	double c{-10}; //test with c{0} also.
	
	a = static_cast<double>(b)/c;
	cout << "b/c without exception : " << a << endl;
	
	cout << "b/c with exception : ";
	try{
		a = Divide(b, c);
	}
	catch(int &ex){ //exception throwed code with type of integer.
		cerr << "Divide by Zero." << endl;
	}
	catch(string &ex){ //exception throwed code with type of string.
		cerr << ex << endl;
	}		
	cout << endl;
	
	return 0;
}