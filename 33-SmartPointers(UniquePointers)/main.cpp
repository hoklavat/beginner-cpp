//33- Smart Pointers (Unique Pointers)

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Test{
private:
	int data;
public:
	Test(): data{0}{cout << "Test Constructor (" << data << ")" << endl;}
	Test(int data): data{data}{cout << "Test Constructor (" << data << ")" << endl;}
	int GetData() const{return data;}
	~Test() {cout << "Test Destructor (" << data << ")" << endl;}	
};

int main(){
	Test t1{10}; //constructor and destructor called	
	Test *t2 = new Test{20}; //only constructor called
	delete t2; //destructor called
	
	unique_ptr<Test> t3{new Test{30}};	
	unique_ptr<Test> t4 = make_unique<Test>(40);	
	unique_ptr<Test> t5;
	//t5 = t3 //error: no assignment/copy
	t5 = move(t3); //makes t3 nullptr

	if(t3 == nullptr) cout << "t3 is now nullptr." << endl;
	cout << "t5->GetData: " << t5->GetData() << endl;
	
	//unique_ptr<Account> a1 = make_unique<Account>(...); //error
	//unique_ptr<Account> a1 = make_unique<Trust_Account>(...); //no error
	
	vector<unique_ptr<Test>> v1;
	v1.push_back(make_unique<Test>(50));
	v1.push_back(make_unique<Test>(60));
	v1.push_back(make_unique<Test>(70));
	for(const auto &t: v1) 
		cout << t->GetData() << endl; //for(auto t: v1) error copy	
	cout << endl;
	
	return 0;
}
