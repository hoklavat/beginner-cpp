//32- Polymorphism 3 (Interface)

#include <iostream>
using namespace std;

class I_Printable{
	friend ostream &operator<<(ostream &os, const I_Printable &obj);
public:
	virtual void Print(ostream &os) const = 0;
	~I_Printable() = default; //compiler generates default destructor
};

ostream &operator<<(ostream &os, const I_Printable &obj){
	obj.Print(os);
	return os;
}

class Base: public I_Printable{
public:
	virtual void Print(ostream &os) const override{
		os << "Base Class.";
	}
};

class Derived: public Base{
public:
	virtual void Print(ostream &os) const override{
		os << "Derived Class.";
	}
};

int main(){
	Base *b1 = new Base();
	Base *b2 = new Derived();
	
	cout << *b1 << endl;
	cout << *b2 << endl; //implementation without interface results in calling base friend method
	
	return 0;
}
