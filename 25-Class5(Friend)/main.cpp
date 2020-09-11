//24- Class 5 (Friend)
//Not Symmetric, Not Transitive

#include <iostream>
using namespace std;

class Test1{
private:
	int n;
	friend void Display(Test1 &t);
	friend class Test2;
	//friend void Test2::Display(Test1 &t);
public:
	Test1(int n){this->n = n;}
};

class Test2{
public:
	void Display(Test1 &t);
};

void Test2::Display(Test1 &t){
	cout << "n: " << t.n << endl;
}

void Display(Test1 &t){
	cout << "n: " << t.n << endl;
}

int main(){
	Test1 t1{10};
	Test2 t2;
	Display(t1);
	t2.Display(t1);
	return 0;
}
