//40-Exception Handling(ClassLevel)
//rather than primitive types a class derived from std::exception class can also be thrown as exception.
//what method returns code for exception.

#include <iostream>
using namespace std;

/*
class IllegalValueException{
public:
	IllegalValueException() = default;
	~IllegalValueException() = default;
};
*/

//inherited from built-in exception class.
class IllegalValueException: public exception{
public:
	IllegalValueException() noexcept = default; //constructor doesn't throw exception.
	~IllegalValueException() = default;
	virtual const char* what() const noexcept{ //what method of std::exception doesn't throw exception.
		return "Exception: Illegal Value.";
	}
};

class Test{
private:
	int x;
	
public:
	Test(): x{0}{
		
	}
	
	Test(int x){
		if(x < 0) throw IllegalValueException{};
		this->x = x;
	}
};

int main(){
	try{
		Test t{-10};
	}
	catch(IllegalValueException &ex){
		cerr << ex.what() << endl;		
	}
	return 0;
}