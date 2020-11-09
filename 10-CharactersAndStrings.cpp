//10-CharactersAndStrings

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

int main(){
	cout << "\n- Characters -" << endl;	
	cout << boolalpha; //show boolean values literally. 0:false, 1:true.
	cout << "isalpha('A') = " << (bool)isalpha('A') << endl; //is alphabetic character?
	cout << "isdigit('5') = " << (bool)isdigit('5') << endl; //is numeric character?
	cout << "isalnum('a') = " << (bool)isalnum('a') << endl; //is alphabetic or numeric character?
	cout << "isupper('A') = " << (bool)isupper('A') << endl; //is uppercase alphabetic character?
	cout << "islower('a') = " << (bool)islower('a') << endl; //is lowercase alphabetic character?
	cout << "isprint('*') = " << (bool)isprint('*') << endl; //is printable character? alphabetic, numeric, punctuation, special.
	cout << "ispunct(';') = " << (bool)ispunct(';') << endl; //is punctuation character?
	cout << "isspace('\\t') = " << (bool)isspace('\t') << endl; //is whitespace character? space, tab, return, etc.
	cout << "tolower('A') = " << (char)tolower('A') << endl; //convert to lowercase.
	cout << "toupper('a') = " << (char)toupper('a') << endl; //convert to uppercase.
	
	cout << "\n- Character Arrays -" << endl;	
	char s[20]{"Foo Bar"}; //character array.
	cout << s << endl; //Foo Bar
	
	s[3] = '-';
	cout << s << endl; //Foo-Bar
	
	strcpy(s, "Bar"); //copy string into character array from beginning.
	cout << s << endl; //Bar
	
	strcat(s, " Foo"); //append string at the end of the character array.
	cout << s << endl; //Bar Foo
	
	cout << "strlen(s) = " << strlen(s) << endl; //7. number of characters in string.
	
	cout << "strcmp(\"Foo\", \"Bar\") = " << strcmp("Foo", "Bar") << endl; //1. compare strings. first string is; less:-1, equal:0, greater:1
	
	cout << "Please, enter your name: ";
	cin.getline(s, 20); //get maximum 20 characters.
	cout << "Your name is " << s << endl;
	
	for(size_t i{0}; i < strlen(s); i++) //size_t = unsigned int
		if(isalpha(s[i])) s[i] = toupper(s[i]); //convert all alphabetic characters to uppercase.
	cout << s << endl;

	cout << "\n- STRINGS -" << endl;
	string s1{"Foo Bar"}; //0th character is F
	string s2{"Foo Bar So Hard", 15}; //15 characters
	string s3{s2, 4}; //Bar So Hard. begins at 4th character, ends at null. null: end of string.
	string s4{s2, 4, 3}; //Bar. begins at 4th character, ends at 4+3=7th character.
	string s5(10, 'F'); //ten times F.
	cout << "s1 = " << s1 << endl; //Foo Bar
	cout << "s2 = " << s2 << endl; //Foo Bar So Hard
	cout << "s3 = " << s3 << endl; //Bar So Hard
	cout << "s4 = " << s4 << endl; //Bar
	cout << "s5 = " << s5 << endl; //FFFFFFFFFF
	
	//cout << "Foo" + "Bar" << endl; //error
	cout << "s1 + s2 = " << s1 + s2 << endl; //join strings.
	cout << "s1[0] = " << s1[0] << ", s1.at(0) = " << s1.at(0) << endl; //character at specific position.
	cout << "(s2 < s3) = " << (s2 < s3) << endl; //string comparision via operators.
	cout << "(s4 == Bar) = " << (s4 == "Bar") << endl;
	cout << "s2.substr(8, 7) = " << s2.substr(8, 7) << endl;
	cout << "s2.find(Bar, 2) = " << s2.find("Bar", 2) << endl; //begin searching from 2nd character. if not found: returns string::npos.	
	
	s5 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "s5 = " << s5 << endl;
	cout << "s5.length() = " << s5.length() << endl;
	s5.erase(0, 3); //delete first three characters from beginning.
	cout << "s5 = " << s5 << endl;
	s5.clear(); //clear whole string.
	cout << "s5 = " << s5 << endl;
	s5 = "1234567890";
	cout << "s5 = " << s5 << endl;
	for(char c: s2) cout << c << " "; //print each character in string with adding space between them.
	cout << endl;
	
	return 0;
}