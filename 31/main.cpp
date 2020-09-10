//31- Polymorphism 2 (Abstract Class)

#include <iostream>
using namespace std;

class Shape{ //Abstract Base Class
public:
	~Shape(){}
	virtual void Draw() = 0; //pure virtual function
	virtual void Rotate() = 0;
};

class Open_Shape: public Shape{
public:
	~Open_Shape(){}
};

class Close_Shape: public Shape{
public:
	~Close_Shape(){}
};

class Line: public Open_Shape{ //Concrete Class
public:
	virtual ~Line(){};
	virtual void Draw() override {cout << "Line is Drawn." << endl;}
	virtual void Rotate() override {cout << "Line is Rotated." << endl;}
};

class Circle: public Close_Shape{ //Concrete Class
public:
	virtual ~Circle(){};
	virtual void Draw() override {cout << "Circle is Drawn." << endl;}
	virtual void Rotate() override {cout << "Circle is Rotated." << endl;}
};

class Square: public Close_Shape{ //Concrete Class
public:
	virtual ~Square(){};
	virtual void Draw() override {cout << "Square is Drawn." << endl;}
	virtual void Rotate() override {cout << "Square is Rotated." << endl;}
};

int main(){
	//Abstract Classes are not instantiatable
	//Shape s1;
	//Shape *p1 = new Shape();
	//Open_Shape o1;
	//Open_Shape *p2 = new Open_Shape();
	//Close_Shape c1;
	//Close_Shape *p3 = new Close_Shape();
	
	Circle c1;
	c1.Draw();
	c1.Rotate();
	cout << endl;

	Shape *p1 = new Circle();
	p1->Draw();
	p1->Rotate();
	delete p1;
	
	return 0;
}
