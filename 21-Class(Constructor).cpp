//21-Class(Constructor)
//class groups relevant objects and methods in a logical manner. Example: Human class has specific physical properties and functionalities.
//constructor creates an instance based on class definition. Example: Einstein is an instance of a Human.

#include <iostream>
#include <string>
using namespace std;

class Human{
public: //public members are accessible outside of the class.

	//Attributes = Properties
	int Age{0};
	int Weight{0};
	int Height{0};
	
	//Default Constructor, if not implemented, empty constructor is created automatically.
	Human(){
		cout << "Human: no-arg constructor is called." << endl;
	}
	
	//One-Arg Constructor
	Human(int a){
		Age = a;
		cout << "Human: one-arg constructor is called." << endl;
	}
	
	//Two-Arg Constructor
	Human(int a, int w){
		Age = a; 
		Weight = w; 
		cout << "Human: two-arg constructor is called." << endl;
	}
	
	//Three-Arg Constructor
	Human(int a, int w, int h){
		Age = a; 
		Weight = w;
		Height = h;
		cout << "Human: three-arg constructor is called." << endl;
	}
	
	//Destructor
	~Human(){
		cout << "Human: destructor is called." << endl;
	}
	
	//Inline Method Implementation	
	void ShowInfo() const{
		cout << "Age: " << Age << ", Weight: " << Weight << "kg, Height: " << Height << "cm." << endl;
		//Age = 15; ERROR: const keyword prevents value modification inside this function.
	} 
};

class Identity{
	
private:  //private members are not accessible outside of the class.
	int ID{0};
	int BirthYear{0};
	string BirthPlace{"?"};
	
public:
	string FirstName{"?"};
	string LastName{"?"};
	
	Identity();
	Identity(int i, int y, string p, string n, string l);
	
	~Identity(){
		cout << "Identity: destructor is called." << endl;
	}
	
	//Copy Constructor: takes existing instance of class then creates exact copy of it.
	Identity(const Identity &i);
	
	void SetInfo(int i, int y, string p, string n, string l){
		ID = i;
		BirthYear = y;
		BirthPlace = p;
		FirstName = n;
		LastName = l;
	}
	
	void ShowInfo();	
};

//Constructor implementation outside of class block.
//Constructor Delegating: another constructor can be used for initialization.
Identity::Identity(): Identity{1, 1881, "Selanik", "Mustafa", "Kemal"}{ //default initialization
	cout << "Identity: no-arg constructor is called." << endl;
}

Identity::Identity(int i, int y, string p, string n, string l){
	cout << "Identity: five-arg constructor is called." << endl;
	ID = i; //"this->ID = i" is also valid. this specifies current insance of class.
	BirthYear = y;
	BirthPlace = p;
	FirstName = n;
	LastName = l;	
}

//Copy Constructor
Identity::Identity(const Identity &i): Identity(i.ID, i.BirthYear, i.BirthPlace, i.FirstName, i.LastName){
	cout << "Identity: copy constructor is called. " << endl;
}

//Method implementation outside of class block.
void Identity::ShowInfo(){
	cout<< "ID Number: " << ID << ", ";
	cout<< "First Name: " << FirstName << ", ";
	cout<< "Last Name: " << LastName << ", ";
	cout<< "Birth Year: " << BirthYear << ", ";
	cout<< "Birth Place: " << BirthPlace << endl;
};

int main(){
	
	Human h1; //Human h1 is 0 years old, 0kg and 0cm
	Human *h2 {new Human{20, 60}}; //Human h2 is 20 years old and 60kg
	Human *h3 = new Human{40, 75, 198}; //Human h3 is 40 years old, 75kg and 198cm
	const Human h4{50, 55, 167};	
	
	cout << endl << "Human h1 Information: " << endl;
	h1.ShowInfo();
	h1.Age = 25;
	h1.Weight = 76;
	h1.Height = 183;
	cout << endl << "Human h1 New Information: " << endl;
	h1.ShowInfo();
	
	cout << endl << "Human h2 Information: " << endl;
	h2->ShowInfo();
	(*h2).Age = 40; //(*h2). same as h2->
	h2->Weight = 67;
	h2->Height = 170;
	cout << endl << "Human h2 New Information: " << endl;
	h2->ShowInfo();
	delete h2; //manual destruction to free up memory.
	
	cout << endl << "Human h3 Information: " << endl;
	h3 -> ShowInfo();
	delete h3;
	cout << endl;
	
	cout <<  "Human h4 Information: " << endl;
	h4.ShowInfo();
	//h4.Age = 10; //ERROR: constant value cannot be changed.
	cout << endl;

	Identity i1;
	Identity i2;
	cout << endl << "Identity i1 Information: " << endl;
	i1.ShowInfo();
	i1.SetInfo(2, 1879, "Ulm", "Albert", "Einstein");
	cout << endl << "Identity i1 NewInformation: " << endl;
	i1.ShowInfo();
	cout << endl << "Identity i2 Information: " << endl;
	i2.ShowInfo();
	//i2.ID = 4; ERROR: private member access outside of class.
	cout << endl << "End of Program: automatic destructors are calling..." << endl;

	return 0;
}