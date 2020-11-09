//25-Class(Friend)
//class or method can access the protected and private members of another class that marks them as friend.
//not symmetric: class cannot access private/protected members of friend class until it is marked by friend class as friend.  
//not transitive: class that is inherited from another class cannot access private/protected members of class that marked later as friend.

#include <iostream>
using namespace std;

class BaseClass{
private:
	int n;
	friend class FriendClass; //can access n directly.
	friend void FriendMethod(BaseClass &b);	
	//friend void FriendClass::Display(Test1 &t); //rather than allowing whole class, specific method can 
	
public:
	BaseClass(int n){
		this->n = n;
	}
};

class FriendClass{
public:
	void Display(BaseClass &b);
};

void FriendClass::Display(BaseClass &b){
	cout << "FriendClass::Display >> n = " << b.n << endl;
}

void FriendMethod(BaseClass &b){
	cout << "FriendMethod >> n = " << b.n << endl;
}

int main(){
	BaseClass b1{10};
	FriendClass f1;
	
	f1.Display(b1);
	FriendMethod(b1);
	
	return 0;
}
