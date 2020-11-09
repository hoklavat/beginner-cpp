//22-Class(CopyConstructor)
//shallow copy constructs a new compound object and then inserts references into it to the objects found in the original. holds references to original.
//deep copy constructs a new compound object and then inserts copies into it of the objects found in the original. duplicate everything.

#include <iostream>
using namespace std;

class Shallow{
private:
	int *data;
	
public:
	void SetData(int d){ //setter
		*data = d;
	}
	
	int GetData(){ //getter
		return *data;
	}
	
	Shallow(int d);
	Shallow(const Shallow &s);
	~Shallow();
};

Shallow::Shallow(int d){
	cout << "Shallow: constructor is called." << endl;
	data = new int; //allocate data on heap for pointer variable before assigning any value.
	*data = d;
}

Shallow::Shallow(const Shallow &s): data(s.data){ //shallow copy: holds references. s.data is address of data not its value.
	cout << "Shallow: copy constructor is called." << endl;	
}

Shallow::~Shallow(){
	delete data; //free-up memory
	cout << "Shallow: destructor is called." << endl;
}

class Deep{
private:
	int *data;
	
public:
	void SetData(int d){
		*data = d;
	}
	
	int GetData(){
		return *data;
	}
	
	Deep(int d);
	Deep(const Deep &d);
	~Deep();
};

Deep::Deep(int d){
	cout << "Deep: constructor is called." << endl;
	data = new int;
	*data = d;
}

Deep::Deep(const Deep &d): data(d.data){
	cout << "Deep: copy constructor is called." << endl;
	data = new int;
	*data = *d.data; //deep copy: assigns values. *d.data is value of data not its address.
}

/* Alternative Deep Constructor
Deep::Deep(const Deep &d): Deep(*d.data){
	cout << "Deep: copy constructor is called." << endl;
}
*/

Deep::~Deep(){
	delete data;
	cout << "Deep: destructor is called." << endl;
}

void DisplayShallow(Shallow s){
	cout << "Begin of DisplayShallow." << endl;
	cout << s.GetData() << endl;
	cout << "End of DisplayShallow." << endl;
}

void DisplayDeep(Deep d){
	cout << "Begin of DisplayDeep." << endl;
	cout << d.GetData() << endl;
	cout << "End of DisplayDeep." << endl;
}

int main(){
	cout << endl << "------------------0--------------------" << endl;
	Shallow s1{100};
	
	cout << endl << "------------------1--------------------" << endl;
	DisplayShallow(s1);
	
	cout << endl << "------------------2--------------------" << endl;	
	Shallow s2{s1};
	
	cout << endl << "------------------3--------------------" << endl;
	//s2.SetData(200); ERROR: shallow 
	DisplayShallow(s2);
	
	cout << endl << "------------------4--------------------" << endl;	
	Deep d1{300};
	
	cout << endl << "------------------5--------------------" << endl;
	DisplayDeep(d1);
	
	cout << endl << "------------------6--------------------" << endl;	
	Deep d2{d1};
	
	cout << endl << "------------------7--------------------" << endl;
	d2.SetData(400);
	DisplayDeep(d2);
	
	cout << endl << "------------------8--------------------" << endl;
	
	return 0;
}