//10- Characters and Strings

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

int main(){
	cout << boolalpha;
	cout << "isalpha('A') = " << isalpha('A') << endl;
	cout << "isdigit('5') = " << isdigit('5') << endl;
	cout << "isalnum('a') = " << isalnum('a') << endl;
	cout << "isupper('A') = " << isupper('A') << endl;
	cout << "islower('a') = " << islower('a') << endl;
	cout << "isprint('*') = " << isprint('*') << endl; //printable character
	cout << "ispunct(';') = " << ispunct(';') << endl; //punctuation character
	cout << "isspace('\t') = " << isspace('\t') << endl; //whitespace character
	cout << "tolower('A') = " << (char)tolower('A') << endl;
	cout << "toupper('a') = " << (char)toupper('a') << endl;
	
	char s1[20]{"Baris"}; //character array, junk initialization, NULL = 8
	s1[5] = 'z';
	cout << s1 << endl;
	//s1 = "Yildiz"; //error
	strcpy(s1, "Yildiz");
	cout << s1 << endl;
	strcat(s1, "Baris");
	cout << s1 << endl;
	cout << "strlen(s1) = " << strlen(s1) << endl;
	cout << "strcmp(\"Baris\", \"Baris\") = " << strcmp("Baris", "Baris") << endl;//-1, 0, 1
	
	cout << "Enter your full name: ";
	cin.getline(s1, 20);
	cout << s1 << endl;
	for(size_t i{0}; i < strlen(s1); i++) //size_t = unsigned int
		if(isalpha(s1[i])) s1[i] = toupper(s1[i]);
	cout << s1 << endl;
	
	string s2{"John McClane Die Hard", 12};
	string s3{s2, 5};
	string s4{s2, 0, 4};
	string s5(10, 'J');
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;	
	cout << "s3 + s4 = " << s3 + " " + s4 << endl;
	//cout << "McClane" + "John" << endl; //error
	cout << "s2[0] = " << s2[0] << ", s2.at(0) = " << s2.at(0) << endl;
	cout << "(s2 < s3) = " << (s2 < s3) << endl;
	cout << "(s3 == McClane) = " << (s3 == "McClane") << endl;
	cout << "s2.substr(5, 7) = " << s2.substr(5, 7) << endl;
	cout << "s2.find(McClane, 4) = " << s2.find("McClane", 4) << endl; //not found: string::npos
	cout << "s5 = " << s5 << endl;
	cout << "s5.length() = " << s5.length() << endl;
	s5.erase(0, 3);
	cout << "s5 = " << s5 << endl;
	s5.clear();
	cout << "s5 = " << s5 << endl;
	s5 = "1234567890";
	cout << "s5 = " << s5 << endl;
	for(char c: s2) cout << c << " ";
	cout << endl;
	return 0;
}
