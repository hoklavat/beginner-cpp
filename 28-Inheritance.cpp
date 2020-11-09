//28-Inheritance

#include <iostream>
using namespace std;

class Base{
public:
	int public_b;
	
	Base();
	Base(int b);
	Base(const Base &other);
	Base &operator=(const Base &rhs);
	~Base();
	
	void DisplayBase();
	void Set(int b1, int b2, int b3);
	
private:
	int private_b;
	
protected:
	int protected_b;
};

Base::Base(): public_b{0}, private_b{0}, protected_b{0}{
	//cout << "Base: no-arg constructor is called." << endl;
}

Base::Base(int b): public_b{b}, private_b{b}, protected_b{b}{
	//cout << "Base: one-arg constructor is called." << endl;
}

Base::Base(const Base &other): public_b{other.public_b}, private_b{other.private_b}, protected_b{other.protected_b}{
	//cout << "Base: copy constructor is called." << endl;
}

//Assignment Operator
Base &Base::operator=(const Base &rhs){
	if(this == &rhs)
		return *this;
	public_b = rhs.public_b;
	private_b = rhs.private_b;
	protected_b = rhs.protected_b;
	return *this;
}

Base::~Base(){
	//cout << "Base: destructor is called." << endl;
}

void Base::DisplayBase(){
	cout << "Base::public_b = " << public_b << ", "
		 << "Base::private_b = " << private_b << ", "
		 << "Base::protected_b = " << protected_b << endl;
}

void Base::Set(int b1, int b2, int b3){
	public_b = b1;
	private_b = b2;
	protected_b = b3;
}

class Derived: public Base{
	//using Base::Base;
public:
	int public_d;
	
	Derived();
	Derived(int d);
	Derived(const Derived &other);
	Derived &operator=(const Derived &rhs);
	~Derived();
	
	void DisplayDerived();
	void Set(int d1, int d2, int d3, int d4); //Override
};

Derived::Derived():Base{}{
	//cout << "Derived: no-arg constructor is called." << endl;
}

Derived::Derived(int d):Base(d), public_d{d}{ //Base(x): call base class one-arg constructor
	//cout << "Derived: one-arg constructor is called." << endl;
}

Derived::Derived(const Derived &other):Base(other), public_d{other.public_d}{
	//cout << "Derived: copy constructor is called." << endl;
}

Derived &Derived::operator=(const Derived &rhs){
	if(this == &rhs)
		return *this;
	Base::operator=(rhs);
	public_d = rhs.public_d;
	return *this;
}

Derived::~Derived(){
	//cout << "Derived: destructor is called." << endl;
}

void Derived::DisplayDerived(){
	cout << "Base::public_b = " << public_b << ", " //public and private variables of base class are accessible.
		 << "Base::protected_b = " << protected_b << ", "
		 << "Derived::public_d = " << public_d << endl; //private variable of base class is not accesible.
}

void Derived::Set(int d1, int d2, int d3, int d4){
	Base::Set(d1, d2, d3); //calling method of base class.
	public_d = d4;
}

int main(){
	Base b1;	
	b1.Set(1, 2, 3);
	b1.DisplayBase();
	
	Derived d1;	
	d1.Set(10, 20, 30, 40);
	d1.DisplayDerived(); //method of derived class cannot access private member of base class.
	d1.DisplayBase(); //derived class can access private member of base class via method implemented in base class. 

	return 0;
}