//40- Exception Handling (Class-Level)

#include <iostream>
using namespace std;

/*
class IllegalValueException{
public:
	IllegalValueException() = default;
	~IllegalValueException() = default;
};
*/

class IllegalValueException: public exception{
public:
	IllegalValueException() noexcept = default;
	~IllegalValueException() = default;
	virtual const char* what() const noexcept{
		return "Error: Illegal Value. (std::exception)";
	}
};

class Test{
private:
	int x;
public:
	Test(): x{0}{}
	Test(int x){
		if(x < 0) throw IllegalValueException{};
		this->x = x;
	}
};

int main(){
	try{
		Test t1{-10};
	}
	catch(IllegalValueException &ex){
		//cerr << "Error: Illegal Value." << endl;
		cerr << ex.what() << endl;		
	}
	return 0;
}
