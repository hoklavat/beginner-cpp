//14- Arguments by Reference

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void FillArray(/*const*/ int [], size_t, int); //const keyword prohibit value change in function
void SetValue(int &, int);
void SetVector(vector<string> &, vector<string>);

int main(){
	int a1[] = {10, 20, 30, 40, 50};
	FillArray(a1, 5, 1);
	for(size_t i: a1)
		cout << i << " ";
	cout << endl;
	
	int n1{100};
	cout << "n1 before SetValue: " << n1 << endl;
	SetValue(n1, 200);
	cout << "n1 after SetValue: " << n1 << endl;
	
	vector<string> v1 {"Baris", "Boris", "Bruce"};
	for(string s: v1)
		cout << s << " ";
	cout << endl;
	SetVector(v1, {"Bar", "Bor", "Bur", "Zort"});
	for(string s: v1)
		cout << s << " ";
	cout << endl;	
	return 0;
}

void FillArray(/*const*/ int a1[], size_t n1, int n2) {
	for(size_t i = 0; i < n1; i++)
		a1[i] = n2;
}

void SetValue(int &n1, int new_value){
	n1 = new_value;
}

void SetVector(vector<string> &v1, vector<string> v2){
	for(size_t i = 0; i < v1.size(); i++){
		if(i > v2.size()) break;
		v1[i] = v2[i];
	}		
}