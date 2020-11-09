//36-SmartPointers(CustomDeleters)
//custom deleter performs memory release operation for smart pointers.
//smart pointers accepts function or lambda expression as an argument for custom deletion operations.

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Test{
private:
	int data;
	
public:
	Test(): data{0}{
		cout << "Test: no-arg constructor is called. (" << data << ")" << endl;
	}
	
	Test(int data): data{data}{
		cout << "Test: one-arg constructor is called. (" << data << ")" << endl;
	}
	
	~Test(){
		cout << "Test: destructor is called. (" << data << ")" << endl;
	}	
	
	int GetData() const{
		return data;
	}	
};

void MyDeleter(Test *ptr){
	cout << "Custom function deleter is called." << endl;
	delete ptr;
}

int main(){
	
	//custom deletion using function.
	{
		shared_ptr<Test> p1{new Test{100}, MyDeleter}; //function as argument.
	}	
	cout << endl;
	
	//custom deletion using lambda expression.
	{
		shared_ptr<Test> p2(new Test{100}, [](Test *ptr){cout << "Custom lambda deleter is called." << endl;delete ptr;}); //lambda as argument.
	}
	cout << endl;
	
	return 0;
}