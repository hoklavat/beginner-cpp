//31-Polymorphism(AbstractClass)
//concrete class: fully implemented class. instantiable.
//abstract class: no implementation. not instantiable. provides general perspective for derived classes.

#include <iostream>
using namespace std;

//Base Abstract Class
class Shape{ 
public:
	~Shape(){}
	virtual void Draw() = 0; //pure virtual function, can only be implemented in derived class.
	virtual void Rotate() = 0;
};

//Derived Abstract Class
class OpenShape: public Shape{
public:
	~OpenShape(){}
};

class CloseShape: public Shape{
public:
	~CloseShape(){}
};

//Derived Concrete Class: contains implementation of methods derived from abstract class.
class Line: public OpenShape{ 
public:
	virtual ~Line(){};
	
	virtual void Draw() override {
		cout << "Line: a line is drawn." << endl;
	}
	virtual void Rotate() override {
		cout << "Line: a line is rotated." << endl;
	}
};

class Circle: public CloseShape{
public:
	virtual ~Circle(){};
	virtual void Draw() override {
		cout << "Circle: a circle is drawn." << endl;
	}
	virtual void Rotate() override {
		cout << "Circle: a circle is rotated." << endl;
	}
};

class Square: public CloseShape{
public:
	virtual ~Square(){};
	virtual void Draw() override {
		cout << "Square: a square is drawn." << endl;
	}
	virtual void Rotate() override {
		cout << "Square: a square is rotated." << endl;
	}
};

int main(){
	Circle c1;
	c1.Draw();
	c1.Rotate();
	cout << endl;

	Shape *s1 = new Circle(); //derived class can be casted as base class.
	s1->Draw();
	s1->Rotate();
	delete s1;
	
	return 0;
}
