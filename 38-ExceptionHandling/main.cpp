//38- Exception Handling

#include <iostream>
using namespace std;

double Divide(int a, int b){
	if(b == 0) throw 0;
	if(a < 0 || b < 0) throw string{"Error: Negative Value."};
	return static_cast<double>(a) / b;
}

int main(){
	double a{0};
	int b{-10}, c{-10}; //test with c{0}
	
	a = static_cast<double>(b) / c;
	cout << a << endl;
	
	try{
		Divide(b, c);
	}
	catch(int &ex){
		cerr << "Error: Divide by Zero." << endl;
	}
	catch(string &ex){
		cerr << ex << endl;
	}		
	cout << endl;
	return 0;
}
