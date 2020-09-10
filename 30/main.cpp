//30- Polymorphism 1

#include <iostream>
using namespace std;

class Base /*final*/{ //final class cannot be inherited
protected:
	int x;
public:
	Base(): x{0}{cout << "Base Class Constructor." << endl;}	
	virtual ~Base(){cout << "Base Class Destructor." << endl;}	
	void Display1() const{cout << "Base Class. Static." << endl;}	
	virtual void Display2() const /*final*/ {cout << "Base Class. Dynamic." << endl;}
	virtual void Set(int x){this->x = x; cout << "Base. x: " << x << endl;}
};

class Derived: public Base{
public:
	Derived(){cout << "Derived Class Constructor." << endl;}
	
	//if virtual keyword is not used only base class destructor is called.
	virtual ~Derived(){cout << "Derived Class Destructor." << endl;}
	
	void Display1() const{cout << "Derived Class. Static." << endl;}
	
	//override: error on different signatures
	virtual void Display2() const override{cout << "Derived Class. Dynamic." << endl;}
	
	virtual void Set(int x) override{this->x = x * 2; cout << "Derived. x: " << this -> x << endl;}
	
	
};

void DisplayStatic(const Base &obj){
	obj.Display1();
}

void DisplayDynamic(const Base &obj){
	obj.Display2();
}

void SetReference(Base &obj, int x){
	obj.Set(x);
}

int main(){	
	Base b1;
	Derived d1;
	Base *b2 = new Base();
	Base *b3 = new Derived();
	
	b1.Display1();
	b1.Display2();
	DisplayStatic(b1);
	DisplayDynamic(b1);
	cout << endl;
	
	d1.Display1();
	d1.Display2();
	DisplayStatic(d1);
	DisplayDynamic(d1);
	cout << endl;
	
	b2->Display1();
	b2->Display2();
	DisplayStatic(*b2);
	DisplayDynamic(*b2);
	cout << endl;
	
	b3->Display1();
	b3->Display2();
	DisplayStatic(*b3);
	DisplayDynamic(*b3);
	cout << endl;
	
	delete b2; //Base Destructor
	delete b3; //Derived Destructor + Base Destructor
	cout << endl;
	
	Base b4;
	Base &r1 = b4;
	r1.Set(10); //Base::Set
	SetReference(b4, 20);
	cout << endl;

	Derived d2;
	Base &r2 = d2;
	r2.Set(30); //Derived::Set
	SetReference(d2, 40);
	cout << endl;

	return 0;
}
