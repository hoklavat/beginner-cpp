//37-SmartPointers(Example)

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Test{
private:
	int data;
	
public:
	Test(): data{0}{
		cout << "Test: no-arg constructor is called. (" << data << ")" << endl;
	}
	
	Test(int data): data{data}{
		cout << "Test: one-arg constructor is called. (" << data << ")" << endl;
	}
	
	int GetData() const{
		return data;
	}
	
	~Test(){
		cout << "Test: destructor is called. (" << data << ")" << endl;
	}
};

//unique pointer that points to vector of shared pointers which are pointing to instances of Test class.
unique_ptr<vector<shared_ptr<Test>>> Make(); //construct smart pointer via function.
void Fill(vector<shared_ptr<Test>> &v, int n); //fill instances with arbitrary numbers.
void Display(vector<shared_ptr<Test>> &v); //display contents of instances.

unique_ptr<vector<shared_ptr<Test>>> Make(){ //auto Make()
	return make_unique<vector<shared_ptr<Test>>>();
}

void Fill(vector<shared_ptr<Test>> &v, int n){
	cout << "- Begin of fill function -" << endl;
	for(int i = 0; i < n; i++){		
		shared_ptr<Test> p = make_shared<Test>(i * 10); //vec.push_back(make_shared<Test>(i * 10));
		v.push_back(p);		
	}
	cout << "- End of fill function -" << endl;
}

void Display(vector<shared_ptr<Test>> &v){
	cout << "- Begin of display function -" << endl;
	for(const auto &p: v)
		cout << p->GetData() << endl;
	cout << "- End of display function -" << endl;
}

int main(){
	unique_ptr<vector<shared_ptr<Test>>> p;
	p = Make(); //construction using function.
	
	Fill(*p, 10);
	cout << endl;
	
	Display(*p);	
	cout << endl;
	
	return 0;
}