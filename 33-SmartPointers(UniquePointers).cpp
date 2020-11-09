//33-SmartPointers(UniquePointers)
//only one unique pointer can point to specific memory address.

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Test{
private:
	int data;
	
public:
	Test(): data{0}{
		cout << "Test: constructor of instance (" << data << ") is called." << endl;
	}
	
	Test(int data): data{data}{
		cout << "Test: constructor of instance (" << data << ") is called." << endl;
	}
	
	int GetData() const{
		return data;
	}
	
	~Test() {
		cout << "Test: destructor of instance (" << data << ") is called." << endl;
	}	
};

int main(){
	Test t1{10};
	
	Test *t2 = new Test{20};
	delete t2;
	
	unique_ptr<Test> t3{new Test{30}};
	
	unique_ptr<Test> t4 = make_unique<Test>(40);
	
	unique_ptr<Test> t5;
	
	//Assignment and Copy: neither assignment nor copy is allowed.
	//t5 = t3
	
	//Move Semantics
	t5 = move(t3); //t5 delegates t3. t3 is disposed.
	if(t3 == nullptr) cout << endl << "t3 is disposed." << endl;	
	cout << "t5->GetData: " << t5->GetData() << endl;
	
	cout << endl;
	vector<unique_ptr<Test>> v1;
	v1.push_back(make_unique<Test>(50));
	v1.push_back(make_unique<Test>(60));
	v1.push_back(make_unique<Test>(70));
	for(const auto &t: v1) 
		cout << t->GetData() << endl; //elements of v1 are pointer, so t is a reference item.
		
	cout << endl;
	
	return 0;
}