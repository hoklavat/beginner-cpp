//36- Smart Pointers (Custom Deleters)

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Test{
private:
	int data;
public:
	Test(): data{0}{cout << "Test No-Arg Constructor (" << data << ")" << endl;}
	Test(int data): data{data}{cout << "Test One-Arg Constructor (" << data << ")" << endl;}
	int GetData() const{return data;}
	~Test() {cout << "Test Destructor (" << data << ")" << endl;}	
};

void MyDeleter(Test *ptr){
	cout << "Custom Deleter." << endl;
	delete ptr;
}

int main(){
	
	//Custom Deleter Using Function
	{
		shared_ptr<Test> ptr1{new Test{100}, MyDeleter};		
	}	
	cout << endl;
	
	//Custom Deleter Using Lamda Expression
	{
		shared_ptr<Test> ptr2(new Test{100}, 
			[](Test *ptr){
				cout << "Custom Lambda Deleter." << endl;
				delete ptr;
			});
	}
	cout << endl;
	
	return 0;
}
