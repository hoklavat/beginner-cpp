//15- Scope

#include <iostream>
using namespace std;

int n1{1};
void PrintGlobal();
void PrintStatic();

int main(){
	int n1{10};
	int n2{20};
	
	{
		int n2{30};
		cout << "n1 = " << n1 << endl;
		cout << "n2 = " << n2 << endl;
	}
	
	PrintGlobal();	
	for(int i = 0; i < 10; i++)
		PrintStatic();
	cout << endl;	
	return 0;
}

void PrintGlobal()
{
	cout << "n1 = " << n1 << endl;	
}

void PrintStatic()
{
	static int n1{0};
	cout << n1 << " ";
	n1++;
}
