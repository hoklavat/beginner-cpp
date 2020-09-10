//28- Inheritance 1

#include <iostream>
using namespace std;

class Base{
public:
	int public_x;
	Base();
	Base(int x);
	Base(const Base &other);
	Base &operator=(const Base &rhs);
	~Base();
	void Display();
	void Set(int x1, int x2, int x3);
private:
	int private_x;
protected:
	int protected_x;
};

Base::Base():public_x{0}, private_x{0}, protected_x{0}{
	cout << "Base No-Arg Constructor." << endl;
}

Base::Base(int x):public_x{x}, private_x{x}, protected_x{x}{
	cout << "Base One-Arg Constructor." << endl;
}

Base::Base(const Base &other):public_x{other.public_x}, private_x{other.private_x}, protected_x{other.protected_x}{
	cout << "Base Copy Constructor." << endl;
}

Base &Base::operator=(const Base &rhs){
	cout << "Base Operator =" << endl;
	if(this == &rhs)
		return *this;
	public_x = rhs.public_x;
	private_x = rhs.private_x;
	protected_x = rhs.protected_x;
	return *this;
}

Base::~Base(){
	cout << "Base Destructor." << endl;
}

void Base::Display(){
	cout << "Base::public_x = " << public_x << ", "
	<< "Base::private_x = " << private_x << ", "
	<< "Base::protected_x = " << protected_x << endl;
}

void Base::Set(int x1, int x2, int x3){
	public_x = x1;
	private_x = x2;
	protected_x = x3;
}

class Derived1:public Base{
	//using Base::Base;
public:
	int public_x1;
	Derived1();
	Derived1(int x);
	Derived1(const Derived1 &other);
	Derived1 &operator=(const Derived1 &rhs);
	~Derived1();
	void Display2();
	void Set(int x1, int x2, int x3, int x4); //Override
};

Derived1::Derived1():Base{}{
	cout << "Derived1 No-Arg Constructor." << endl;
}

Derived1::Derived1(int x):Base(x), public_x1{x}{ //Base(x): call base class one-arg constructor
	cout << "Derived1 One-Arg Constructor." << endl;
}

Derived1::Derived1(const Derived1 &other):Base(other), public_x1{other.public_x1}{
	cout << "Derived1 Copy Constructor." << endl;
}

Derived1 &Derived1::operator=(const Derived1 &rhs){
	cout << "Derived Operator =" << endl;
	if(this == &rhs)
		return *this;
	Base::operator=(rhs);
	public_x1 = rhs.public_x1;
	return *this;
}

Derived1::~Derived1(){
	cout << "Derived1 Destructor." << endl;
}

void Derived1::Display2(){
	cout << "Base::public_x = " << public_x << ", "
	<< "Base::protected_x = " << protected_x << ", "
	<< "Derived1::public_x1 = " << public_x1 << endl; //private_x not accessible
}

void Derived1::Set(int x1, int x2, int x3, int x4){
	Base::Set(x1, x2, x3); //Base Method Call
	public_x1 = x4;
}

int main(){
	//if one-arg constructor not implemented base class one-arg constructor called
	Base b1{1};
	Base b2{b1};
	b2 = b1;
	b1.Display();
	b1.Set(1, 2, 3);
	b1.Display();
	cout << endl;

	Derived1 d1{1};
	Derived1 d2{d1};
	d2 = d1;
	d1.Display();
	d1.Display2();
	d1.Set(1, 2, 3, 4);
	d1.Display();
	d1.Display2();
	cout << endl;

	return 0;
}
