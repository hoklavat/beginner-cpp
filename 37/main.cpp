//37- Smart Pointers (Example)

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Test{
private:
	int data;
public:
	Test(): data{0}{cout << "Test No-Arg Constructor (" << data << ")" << endl;}
	Test(int data): data{data}{cout << "Test One-Arg Constructor (" << data << ")" << endl;}
	int GetData() const{return data;}
	~Test(){cout << "Test Destructor (" << data << ")" << endl;}
};

unique_ptr<vector<shared_ptr<Test>>> Make(); //auto Make()
void Fill(vector<shared_ptr<Test>> &vec, int num);
void Display(vector<shared_ptr<Test>> &vec);

unique_ptr<vector<shared_ptr<Test>>> Make(){ //auto Make()
	return make_unique<vector<shared_ptr<Test>>>();
}

void Fill(vector<shared_ptr<Test>> &vec, int num){
	for(int i = 0; i < num; i++){
		//vec.push_back(make_shared<Test>(i * 10));
		shared_ptr<Test> ptr = make_shared<Test>(i * 10);
		vec.push_back(ptr);		
	}		
}

void Display(vector<shared_ptr<Test>> &vec){
	for(const auto &ptr: vec)
		cout << ptr->GetData() << endl;
}

int main(){
	unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
	vec_ptr = Make();
	Fill(*vec_ptr, 10);
	Display(*vec_ptr);	
	cout << endl;
	return 0;
}
