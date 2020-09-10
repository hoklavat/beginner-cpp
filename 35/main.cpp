//35- Smart Pointers (Weak Pointers)

#include <iostream>
#include <memory>
using namespace std;

class B; //forward declaration

class A{
	shared_ptr<B> b_ptr;
public:
	SetB(shared_ptr<B> &b){b_ptr = b;}
	A(){cout << "A - Constructor." << endl;}
	~A(){cout << "A - Destructor." << endl;}
};

class B{
	//shared_ptr<A> a_ptr; //Memory Leak
	weak_ptr<A> a_ptr;
public:
	SetA(shared_ptr<A> &a){a_ptr = a;}
	B(){cout << "B - Constructor." << endl;}
	~B(){cout << "B - Destructor." << endl;}	
};

int main(){
	shared_ptr<A> a = make_shared<A>();
	shared_ptr<B> b = make_shared<B>();
	a->SetB(b);
	b->SetA(a);	
	cout << endl;

	return 0;
}
