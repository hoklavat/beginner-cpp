//27-OperatorOverloading(Global)
//operators are implemented as friend functions.

#include <iostream>
#include <cstring>
using namespace std;

class MyString{
	friend ostream &operator<<(ostream &os, const MyString &rhs); //stream insertion
	friend istream &operator>>(istream &in, MyString &rhs); //stream extraction	
	friend bool operator==(const MyString &lhs, const MyString &rhs); //equals
	friend bool operator!=(const MyString &lhs, const MyString &rhs); //not equals
	friend bool operator<(const MyString &lhs, const MyString &rhs); //less than
	friend bool operator>(const MyString &lhs, const MyString &rhs); //greater than
	friend MyString operator-(const MyString &obj); //lowercase
	friend MyString operator+(const MyString &lhs, const MyString &rhs); //concatenate
	friend MyString operator*(const MyString &lhs, int n); //repeater
	friend MyString &operator+=(MyString &lhs, const MyString &rhs); //concat and assign
	friend MyString &operator*=(const MyString &lhs, int n); //repeat and assign
	friend MyString &operator++(MyString &obj); //pre-increment
	friend MyString operator++(MyString &obj, int); //post-increment
	
private:
	char *str;
	
public:
	MyString();
	MyString(const char *s);
	MyString(const MyString &source);
	MyString(MyString &&source);
	~MyString();
	
	MyString &operator=(const MyString &rhs);
	MyString &operator=(MyString &&rhs);
	
	void Display() const;
	int GetLength() const;
	const char *GetString() const;
};

MyString::MyString(): str{nullptr}{
	str = new char[1];
	*str = '\0';
}

MyString::MyString(const char *s): str{nullptr}{
	if(s == nullptr){
		str = new char[1];
		*str = '\0';
	}
	else{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}	
}

MyString::MyString(const MyString &source): str{nullptr}{
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

MyString::MyString(MyString &&source):str(source.str){
	source.str = nullptr;
}

MyString::~MyString(){
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

MyString &MyString::operator=(const MyString &rhs){	
	if(this == &rhs)
		return *this;
	delete [] str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(str, rhs.str);
	return *this;
}

MyString &MyString::operator=(MyString &&rhs){
	if(this == &rhs)
		return *this;
	delete [] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

ostream &operator<<(ostream &os, const MyString &rhs){
	os << rhs.str;
	return os;
}

istream &operator>>(istream &in, MyString &rhs){
	char *buff = new char[1000];
	in >> buff;
	rhs = MyString(buff);
	delete [] buff;
	return in;
}

bool operator==(const MyString &lhs, const MyString &rhs){
	return (strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const MyString &lhs, const MyString &rhs){
	return !(strcmp(lhs.str, rhs.str) == 0);
}

bool operator<(const MyString &lhs, const MyString &rhs){
	return (strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const MyString &lhs, const MyString &rhs){
	return (strcmp(lhs.str, rhs.str) > 0);
}

MyString operator-(const MyString &obj){
	char *buff = new char(strlen(obj.str) + 1);
	strcpy(buff, obj.str);
	for(size_t i = 0; i < strlen(buff); i++)
		buff[i] = tolower(buff[i]);
	MyString temp{buff};
	delete [] buff;
	return temp;	
}

MyString operator+(const MyString &lhs, const MyString &rhs){
	char *buff = new char(strlen(lhs.str) + strlen(rhs.str) + 1);
	strcpy(buff, lhs.str);
	strcat(buff, rhs.str);	
	MyString temp{buff};
	delete [] buff;
	return temp;	
}

MyString operator*(const MyString &lhs, int n){
	MyString temp;
	for(int i = 0; i < n; i++)
		temp = temp + lhs;
	return temp;
}

MyString &operator+=(MyString &lhs, const MyString &rhs){
	lhs = lhs + rhs;
	return lhs;
}

MyString &operator*=(MyString &lhs, int n){
	lhs = lhs * n;
	return lhs;
}

MyString &operator++(MyString &obj){
	for(size_t i = 0; i < strlen(obj.str); i++)
		obj.str[i] = toupper(obj.str[i]);
	return obj;
}

MyString operator++(MyString &obj, int){
	MyString temp{obj};
	++obj;
	return temp;
}

int main(){
	MyString m1{"Albert"};
	MyString m2{"Einstein"};
	MyString m3 = m2;
	MyString m4{"Bye"};
	
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