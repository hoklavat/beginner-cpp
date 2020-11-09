//30-Polymorphism

#include <iostream>
using namespace std;

class Base /*final*/{ //final class cannot be inherited.
protected:
	int b;
	
public:
	Base(): b{0}{
		cout << "Base: constructor is called." << endl;
	}
	
	virtual ~Base(){
		cout << "Base: destructor is called." << endl;
	}
	
	//Static Method: if derived class casted as base class, rather than overrided one in derived class, method of base class is called .
	void Method1() const{
		cout << "Base: method 1 is called." << endl;
	}
	
	//Dynamic Method: no matter casted base or derived, overrided method is used for derived class.
	virtual void Method2() const /*final*/ { //final method cannot be overrided.
		cout << "Base: method 2 is called." << endl;
	}
	
	virtual void Set(int b){
		this->b = b; 
		cout << "Base >> b = " << b << endl;
	}
};

class Derived: public Base{
public:
	Derived(){
		cout << "Derived: constructor is called." << endl;
	}
	
	//if virtual keyword is not used only base class destructor is called.
	virtual ~Derived(){
		cout << "Derived: destructor is called." << endl;
	}
	
	void Method1() const{
		cout << "Derived: method 1 is called." << endl;
	}
	
	//override: throws error if signature is different from the method of base class.
	virtual void Method2() const override{
		cout << "Derived: method 2 is called." << endl;
	}
	
	virtual void Set(int b) override{
		this->b = b * 2; 
		cout << "Derived >> b = " << this->b << endl;
	}
};

void MethodStatic(const Base &obj){
	obj.Method1();
}

void MethodDynamic(const Base &obj){
	obj.Method2();
}

void SetReference(Base &obj, int x){
	obj.Set(x);
}

int main(){

	cout << "------------ CONSTRUCTION ------------" << endl;
	Base b1; //base constructor
	cout << endl;
	
	Base *b2 = new Base();
	cout << endl;
	
	Derived d1; //base and derived constructor
	cout << endl;
	
	Base *d2 = new Derived(); //derived casted as base.
	cout << endl;
	
	cout << "------------ BASE METHODS ------------" << endl;
	b1.Method1();
	b1.Method2();
	MethodStatic(b1);
	MethodDynamic(b1);
	cout << endl;
	
	b2->Method1();
	b2->Method2();
	MethodStatic(*b2);
	MethodDynamic(*b2);
	cout << endl;
	
	cout << "------------ DERIVED METHODS ------------" << endl;
	d1.Method1();
	d1.Method2();
	MethodStatic(d1); //derived casted as base. static method. base.
	MethodDynamic(d1); //derived casted as base. dynamic method. derived.
	cout << endl;
	
	d2->Method1();
	d2->Method2();
	MethodStatic(*d2);
	MethodDynamic(*d2);
	cout << endl;
	
	cout << "------------ REFERENCING------------" << endl;
	Base b4;
	Base &r1 = b4;
	r1.Set(10); //Base::Set
	SetReference(b4, 20);
	cout << endl;

	Derived d3;
	Base &r2 = d3; //derived referenced as base.
	r2.Set(10); //Derived::Set
	SetReference(d3, 20);
	cout << endl;
	
	cout << "------------ DESTRUCTION ------------" << endl;
	delete b2;
	cout << endl;
	delete d2;
	cout << endl;

	return 0;
}
