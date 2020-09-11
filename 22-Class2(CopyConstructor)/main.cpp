//22- Class 2 (Copy Constructor)
//Shallow and Deep Copy

#include <iostream>
using namespace std;

class Shallow{
private:
	int *data;
public:
	void SetData(int d){*data = d;}
	int GetData(){return *data;}
	
	Shallow(int d);
	Shallow(const Shallow &s);
	~Shallow();
};

Shallow::Shallow(int d){
	data = new int;
	*data = d;
}

Shallow::Shallow(const Shallow &s): data(s.data){
	cout << "Copy Constructor - Shallow Copy." << endl;	
}

Shallow::~Shallow(){
	delete data;
	cout << "Destructor - Shallow Copy." << endl;
}

void DisplayShallow(Shallow s){
	cout << s.GetData() << endl;
}

class Deep{
private:
	int *data;
public:
	void SetData(int d){*data = d;}
	int GetData(){return *data;}
	
	Deep(int d);
	Deep(const Deep &d);
	~Deep();
};

Deep::Deep(int d){
	data = new int;
	*data = d;
}

/*Deep::Deep(const Deep &d): data(d.data){
	cout << "Copy Constructor - Deep Copy." << endl;
	data = new int;
	*data = *d.data;
}*/

Deep::Deep(const Deep &d): Deep{*d.data}{
	cout << "Copy Constructor - Deep Copy." << endl;
}

Deep::~Deep(){
	delete data;
	cout << "Destructor - Deep Copy" << endl;
}

void DisplayDeep(Deep d){
	cout << d.GetData() << endl;
}

int main(){
	Shallow s1{100};
	DisplayShallow(s1);
	
	Shallow s2{s1};
	s2.SetData(200);
	DisplayShallow(s2);
	
	Deep d1{300};
	DisplayDeep(d1);
	
	Deep d2{d1};
	d2.SetData(400);
	DisplayDeep(d2);
	
	return 0;
}
