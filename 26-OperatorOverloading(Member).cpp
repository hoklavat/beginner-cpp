//26-OperatorOverloading(Member)
//operators are implemented as class members.
//redefining built-in operator to perform class-specific operations.
//get value at right-hand side of operator, perform some operations, return result.

#include <iostream>
#include <cstring>
using namespace std;

class MyString{
	
	//Stream Insertion
	friend ostream& operator<<(ostream &os, const MyString &rhs);
	
	//Stream Extration
	friend istream& operator>>(istream &in, MyString &rhs);
	
private:
	char *str;

public:
	MyString();
	MyString(const char *s);
	MyString(const MyString &source);
	MyString(MyString &&source);
	~MyString();
	
	//Copy Assignment
	MyString &operator=(const MyString &rhs);
	
	//Move Assignment
	MyString &operator=(MyString &&rhs);
	
	//Equal
	bool operator==(const MyString &rhs) const;
	
	//Not Equal
	bool operator!=(const MyString &rhs) const;
	
	//Less Than
	bool operator<(const MyString &rhs) const;
	
	//Greater Than
	bool operator>(const MyString &rhs) const;
	
	//Lowercase
	MyString operator-()const;
	
	//Concatenate
	MyString operator+(const MyString &rhs) const;
	
	//Repeat
	MyString operator*(int n) const;
	
	//Concatenate and Assign
	MyString &operator+=(const MyString &rhs);
	
	//Repeat and Assign
	MyString &operator*=(int n);
	
	//Pre-Increment
	MyString &operator++();
	
	//Post-Increment
	MyString operator++(int);
	
	//Other Methods
	void Display() const;
	int GetLength() const;
	const char *GetString() const;
};

MyString::MyString():str{nullptr}{
	str = new char[1];
	*str = '\0'; //create an empty string.
}

MyString::MyString(const char *s): str{nullptr}{
	if(s == nullptr){
		str = new char[1];
		*str = '\0';
	}
	else{
		str = new char[strlen(s) + 1];
		strcpy(str, s); //copy contents of s to str.
	}	
}

MyString::MyString(const MyString &source): str{nullptr}{
	//cout << "MyString: copy constructor is called." << endl;
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

MyString::MyString(MyString &&source): str(source.str){
	//cout << "MyString: move constructor is called." << endl;
	source.str = nullptr;
}

MyString::~MyString(){
	//cout << "MyString: destructor is called." << endl;
	delete [] str;
}

void MyString::Display() const{
	cout << str << ":" << GetLength() << endl;
}

int MyString::GetLength() const{
	return strlen(str);
}

const char *MyString::GetString() const{
	return str;
}

//Stream Insertion
ostream &operator<<(ostream &os, const MyString &rhs){
	os << rhs.str;
	return os;
}

//Stream Extraction
istream &operator>>(istream &in, MyString &rhs){
	char *buff = new char[1000];
	in >> buff;
	rhs = MyString(buff);
	delete [] buff;
	return in;
}

//Copy Assignment
MyString &MyString::operator=(const MyString &rhs){ //rhs: value at right-hand side of operator.
	//cout << "MyString: copy assignment operation." << endl;
	if(this == &rhs)
		return *this;
	delete [] str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(str, rhs.str);
	return *this; //chain assignment
}

//Move Assignment
MyString &MyString::operator=(MyString &&rhs){
	//cout << "MyString: move assignment operation." << endl;
	if(this == &rhs)
		return *this;
	delete [] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

//Equal
bool MyString::operator==(const MyString &rhs) const{
	return (strcmp(str, rhs.str) == 0);
}

//Not Equal
bool MyString::operator!=(const MyString &rhs) const{
	return !(strcmp(str, rhs.str) == 0);
}

//Less Than
bool MyString::operator<(const MyString &rhs) const{
	return (strcmp(str, rhs.str) < 0);
}

//Greater Than
bool MyString::operator>(const MyString &rhs) const{
	return (strcmp(str, rhs.str) > 0);
}

//Lowercase
MyString MyString::operator-() const{
	char *buff = new char(strlen(str) + 1);
	strcpy(buff, str);
	for(size_t i = 0; i < strlen(buff); i++)
		buff[i] = tolower(buff[i]);
	MyString temp{buff};
	delete [] buff;
	return temp;	
}

//Concatenate
MyString MyString::operator+(const MyString &rhs) const{
	char *buff = new char(strlen(str) + strlen(rhs.str) + 1);
	strcpy(buff, str);
	strcat(buff, rhs.str);
	MyString temp{buff};
	delete [] buff;
	return temp;
}

//Repeat
MyString MyString::operator*(int n) const{
	MyString temp;
	for(int i = 0; i < n; i++)
		temp = temp + *this; //used class specific concatenation operator.
	return temp;
}

//Concatenate and Assign
MyString &MyString::operator+=(const MyString &rhs){
	*this = *this + rhs;
	return *this;
}

//Repeat and Assign
MyString &MyString::operator*=(int n){
	*this = *this * n;
	return *this;
}

//Uppercase
MyString &MyString::operator++(){
	for(size_t i = 0; i < strlen(str); i++)
		str[i] = toupper(str[i]);
	return *this;
}

MyString MyString::operator++(int){
	MyString temp{*this};
	operator++();
	return temp;
}

int main(){
	MyString m1{"Mustafa"};
	MyString m2{"KEMAL"};
	MyString m3 = m2;
	MyString m4{"Hello"};
	
	cout << "m1 = " << m1 << endl;
	cout << "m2 = " << m2 << endl;
	cout << "m3 = " << m3 << endl;
	cout << "m4 = " << m4 << endl;	
	cout << boolalpha;
	cout << "(m1 == m2) = " << (m1 == m2) << endl;
	cout << "(m1 != m2) = " << (m1 != m2) << endl;
	cout << "(m1 < m2) = " << (m1 < m2) << endl;
	cout << "(m1 > m2) = " << (m1 > m2) << endl;
	
	cout << "-m2 = "  << -m2 << endl;
	cout << "m1 + m2 = " << m1 + m2 << endl;
	cout << "m1 * 5 = " << m1 * 5 << endl;
	
	m1 *= 3;
	cout << "m1 *= 3 : " << m1 << endl;
	
	m1 += m2;
	cout << "m1 += m2 : " << m1 << endl;
	
	m1++;
	cout << "m1++ : " << m1 << endl;
	
	++m4;
	cout << "++m4 : " << m4 << endl;
	
	return 0;
}