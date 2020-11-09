//09-Looping

#include <iostream>
#include <vector>
using namespace std;

int main(){
	for(int i{}, j{8}; i < 5; ++i, j-=2 ) //increment i by 1, decrement j by 2.
		cout << i << "-" << j << " ";
	cout << endl;
	
	vector<int> v{10, 20, 30, 40, 50};
	for(int i{}; i < v.size(); i++) //vector size is 5.
		cout << v[i] << ((i < 4) ? "-" : "\n"); //seperate characters by - and end with \n
		
	for(auto e: v) //auto: type of right hand value (int)
		cout << e << " ";
	cout << endl;
	
	char c{};
	do
	{
		int n1{}, n2{};
		cout << "Enter two numbers seperated by a space: ";
		cin >> n1 >> n2;
		int n3{n1 * n2};
		cout << "Multiplication of two numbers: " << n3 << endl;
		cout << "Do you want to calculate again? (y/n)";
		cin >> c;
	}while(c == 'y' || c == 'Y'); //Invalid: (c != 'n' || c != 'N') Valid: (c != 'n' && c != 'N')
	return 0;
}