//14-ArgumentsByReference
//reference argument denoted by & should be variable like &x, not a fixed value like &12

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void FillArray(/*const*/ int [], size_t, int); //const keyword used to ensure that function shouldn't change the value of the reference input. 
void SetValue(int &, int);
void SetVector(vector<string> &, vector<string>);

int main(){
	int a1[] = {10, 20, 30, 40, 50};
	cout << "a1 before FillArray: ";
	for(size_t i: a1)
		cout << i << " ";
	cout << endl;
	FillArray(a1, 5, 1); //fill with 1s.
	cout << "a1 after FillArray: ";
	for(size_t i: a1)
		cout << i << " ";
	cout << endl;
	
	int n1{100};
	cout << endl << "n1 before SetValue: " << n1 << endl;
	SetValue(n1, 200);
	cout << "n1 after SetValue: " << n1 << endl;
	
	vector<string> v1 {"Ali", "Burhan", "Cemal"};
	cout<< endl <<  "v1 before SetVector: ";
	for(string s: v1)
		cout << s << " ";
	cout << endl;
	SetVector(v1, {"Dincer", "Emrah", "Fenasi", "Gurkan"}); //Gurkan will no
	
	cout << "v1 after SetVector: ";
	for(string s: v1)
		cout << s << " ";
	cout << endl;	
	return 0;
}

//fill first n1 elements of a1 with n2
void FillArray(/*const*/ int a1[], size_t n1, int n2) {
	for(size_t i = 0; i < n1; i++)
		a1[i] = n2;
}

//change value of n1 with new_value. & marks input as reference. fixed value is not accepted as n1.
void SetValue(int &n1, int new_value){
	n1 = new_value;
}

//copy contents of v2 to v1 as far as it fits.
void SetVector(vector<string> &v1, vector<string> v2){
	for(size_t i = 0; i < v1.size(); i++){
		if(i > v2.size()) break; //prevent overflow if v2 has more elements than v1.
		v1[i] = v2[i];
	}		
}