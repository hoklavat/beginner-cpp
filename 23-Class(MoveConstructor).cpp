//23-Class(MoveConstructor)
//move constructor allows the resources owned by an rvalue object to be moved into an lvalue without creating its copy.

#include <iostream>
#include <vector>
using namespace std;

//Left Value Parameter: x = 100 is valid, 100 = x is invalid. 100 is not l-value parameter.
void LV_Test(int &n){
	cout << "l-value test >> n: " << n << endl;
}

//Right Value Parameter: 100 is r-value parameter.
void RV_Test(int &&n){
	cout << "r-value Test >> n: " << n << endl;
}

class Move{
private:
	int *data;
public:
	void SetData(int d){
		*data = d;
	}
	
	int GetData(){
		return *data;
	}
	
	Move(int d);
	Move(const Move &source);
	Move(Move &&source) noexcept; //this expression won't throw any exception at compile time.
	~Move();	
};

Move::Move(int d){
	cout << "Move: one-arg constructor is called. " << endl;
	data = new int;
	*data = d;
}

Move::Move(const Move &source):Move(*source.data){
	cout << "Move: deep copy constructor is called. " << endl;
}

//Move Constructor
Move::Move(Move &&source) noexcept: data{source.data}{
	source.data = nullptr; //data pointer takes over, old pointer is disposable.
	cout << "Move: move constructor is called. " << endl;
}

Move::~Move(){
	if(data != nullptr){
		cout << "Move: destructor is called." << endl;		
	}
	else{
		cout << "Move: destructor from move constructor is called." << endl;
	}
	delete data;
}

int main(){
	int n1{100};
	LV_Test(n1); //LV_Test(100); error	
	RV_Test(200); //RV_Test(n1); error
	
	cout << endl << "-----------------0-----------------" << endl;
	vector<Move> v1;
	
	cout << endl << "-----------------1-----------------" << endl;
	v1.push_back(Move(1));
	
	cout << endl << "-----------------2-----------------" << endl;
	v1.push_back(Move(2));
	
	cout << endl << "-----------------3-----------------" << endl;
	v1.push_back(Move(3));
	
	cout << endl << "-----------------4-----------------" << endl;
	v1.push_back(Move(4));
	
	cout << endl << "-----------------5-----------------" << endl;
	v1.push_back(Move(5));
	
	cout << endl << "-----------------6-----------------" << endl;
	
	return 0;
}