//21- Class 1

#include <iostream>
#include <string>
using namespace std;

class Human{
public:
	//Attributes
	int Age{0};
	int Weight{0};
	int Height{0};
	
	//Constructors
	Human();
	Human(int a, int w){Age = a; Weight = w; cout << "Human Two-Arg Constructor Called." << endl;}
	Human(int a, int w, int h);
	//Human(int a = 0, int w = 0, int h = 0); //default intializers, unique
	
	//Destructor
	~Human(){cout << "Human Destructor Called." << endl;}
	
	//Inline Method Implementation
	//const: content unmodified
	void ShowInfo()const{cout << "Age: " << Age << ", Weight: " << Weight << ", Height: " << Height << endl;} 
};

//Constructor Initialization
Human::Human(): Age{0}, Weight{0}, Height{0} {
	cout << "Human No-Arg Constructor Called." << endl;
}

Human::Human(int a, int w, int h): Age{a}, Weight{w}, Height{h}{
	cout << "Human Three-Arg Constructor Called." << endl;
}

class Identity{
private:
	int ID{0};
	int BirthYear{0};
	string BirthPlace{"0"};	
public:
	string FirstName{"0"};
	string LastName{"0"};
	
	Identity();
	Identity(int i, int y, string p, string n, string l);
	~Identity() {cout << "Identity Destructor Called." << endl;}
	
	//Copy Constructor
	Identity(const Identity &i);
	
	void SetInfo(int i, int y, string p, string n, string l) {ID = i; BirthYear = y; BirthPlace = p; FirstName = n; LastName = l;}
	void ShowInfo();	
};

//Constructor Delegating
Identity::Identity(): Identity{1, 1982, "Norway", "Baris", "Yildiz"}{
	cout << "Identity No-Arg Constructor Called." << endl;
}

Identity::Identity(int i, int y, string p, string n, string l){
	ID = i; //this->ID
	BirthYear = y;
	BirthPlace = p;
	FirstName = n;
	LastName = l;
	cout << "Identity Five-Arg Constructor Called." << endl;
}

Identity::Identity(const Identity &i)
//	: ID(i.ID), BirthYear(i.BirthYear), BirthPlace(i.BirthPlace), FirstName(i.FirstName), LastName(i.LastName){
	: Identity(i.ID, i.BirthYear, i.BirthPlace, i.FirstName, i.LastName){
	cout << "Identity Copy Constructor Called. " << i.FirstName << endl;
}

//Method Implementation
void Identity::ShowInfo(){
	cout<< "ID Number: " << ID << ", ";
	cout<< "First Name: " << FirstName << ", ";
	cout<< "Last Name: " << LastName << ", ";
	cout<< "Birth Year: " << BirthYear << ", ";
	cout<< "Birth Place: " << BirthPlace << endl;
};

void DisplayIdentity(Identity i)
{
	cout << "Copy Constructor Demonstration. " << i.FirstName << endl; 
}

int main(){
	
	Human h1;
	//Human h1{1, 2};
	Human *h2 {new Human{3, 4}};
	Human *h3 = new Human{5, 6, 7};
	
	h1.ShowInfo();
	h1.Age = 10;
	h1.Weight = 20;
	h1.Height = 30;
	h1.ShowInfo();
	
	h2->ShowInfo();
	(*h2).Age = 40;
	h2->Weight = 50;
	h2->Height = 60;
	h2->ShowInfo(); //*(h2).ShowInfo()
	delete h2;
	
	h3 -> ShowInfo();
	delete h3;	
	cout << endl;

	Identity i1;
	Identity i2;
	i1.ShowInfo();
	//i1.ID = 2; //error: private
	i1.SetInfo(2, 1943, "Paris", "Pok", "Emon");
	i1.ShowInfo();	
	DisplayIdentity(i2);
	
	const Human h4{1, 2, 3};
	//h4.Age = 10; //error: constant
	h4.ShowInfo();

	return 0;
}
