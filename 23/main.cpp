//23- Class 3 (Move Constructor)

#include <iostream>
#include <vector>
using namespace std;

//Left Value Parameter
void LV_Test(int &n){
	cout << "n: " << n << endl;
}

//Right Value Parameter
void RV_Test(int &&n){
	cout << "n: " << n << endl;
}

class Move{
private:
	int *data;
public:
	void SetData(int d){*data = d;}
	int GetData(){return *data;}
	
	Move(int d);
	Move(const Move &source);
	Move(Move &&source)noexcept;
	~Move();	
};

Move::Move(int d){
	data = new int;
	*data = d;
	cout << "One-Arg Constructor. " << d << endl;
}

Move::Move(const Move &source):Move(*source.data){
	cout << "Copy Constructor. " << *data << endl;
}

//Move Constructor
Move::Move(Move &&source)noexcept:data{source.data}{
	source.data = nullptr;
	cout << "Move Constructor. " << *data << endl;
}

Move::~Move(){
	if(data != nullptr){
		cout << "Destructor." << *data << endl;		
	}
	else{
		cout << "Destructor. nullptr" << endl;
	}
	delete data;
}

int main(){
	int n1 {100};
	LV_Test(n1); //LV_Test(100); error	
	RV_Test(200); //RV_Test(n1); error
	
	vector<Move> v1;
	v1.push_back(Move(10));
	v1.push_back(Move(20));
	v1.push_back(Move(30));
	v1.push_back(Move(40));
	v1.push_back(Move(50));
	
	return 0;
}
