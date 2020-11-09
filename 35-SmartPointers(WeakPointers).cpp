//35-SmartPointers(WeakPointers)

#include <iostream>
#include <memory>
using namespace std;

class B; //forward declaration of a class

class A{
	shared_ptr<B> b;
	
public:
	SetB(shared_ptr<B> &b){
		this->b = b;
	}
	
	A(){
		cout << "Class A: constructor is called." << endl;
	}
	
	~A(){
		cout << "Class A: destructor is called." << endl;
	}
};

class B{	
	weak_ptr<A> a; //using a shared pointer instead of weak pointer causes memory leak.
public:
	SetA(shared_ptr<A> &a){
		this->a = a;
	}
	
	B(){
		cout << "Class B: constructor is called." << endl;
	}
	
	~B(){
		cout << "Class B: destructor is called." << endl;
	}	
};

int main(){
	shared_ptr<A> a = make_shared<A>();
	shared_ptr<B> b = make_shared<B>();
	a->SetB(b);
	b->SetA(a);	
	cout << endl;

	return 0;
}
