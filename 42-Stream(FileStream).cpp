//42-Stream(FileStream)

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fi; //{"path.filename.extension"}
	ofstream fo; //{"path.filename.extension"}
	
	string line;
	string s;
	char c{};
	int i;
	double d;
	
	//open input file stream.
	fi.open("C:\\0\\Projects\\CodeLite\\0-TEST\\build-Debug\\01\\test.txt");
	if(!fi){
		cerr << "Error: input file couldn't get opened." << endl;
		return 1; //exit(1)
	}
	cout << "Input file is opened." << endl;
	
	//open output file stream.
	fo.open("C:\\0\\Projects\\CodeLite\\0-TEST\\build-Debug\\01\\copy.txt");
	if(!fo){
		cerr << "Error: output file couldn't get opened." << endl;
		return 1;
	}
	cout << "Output file is opened." << endl;
	cout << endl;
	
	//read into different type of variables seperated by spaces.
	cout << "---- READ 1 (variables) ---- " << endl;
	while(!fi.eof()){ //while(in_file >> s1 >> i1 >> d1)
		fi >> s >> i >> d;
		cout << "Name: " << s << ", Age: " << i << ", Height: " << d << endl;
	}
	fi.close();
	cout << endl;
	
	//read into string line by line.
	cout << "---- READ 2 (line) ---- " << endl;
	fi.open("C:\\0\\Projects\\CodeLite\\0-TEST\\build-Debug\\01\\test.txt");
	while(getline(fi, line))
		cout << line << endl;
	fi.close();
	cout << endl;
	
	//read into one character at a time.
	cout << "---- READ 3 (character) ---- " << endl;
	fi.open("C:\\0\\Projects\\CodeLite\\0-TEST\\build-Debug\\01\\test.txt");
	while(fi.get(c)){
		cout << c;
	}
	fi.close();
	cout << endl;
	
	//make an encrypted copy of file.
	fi.open("C:\\0\\Projects\\CodeLite\\0-TEST\\build-Debug\\01\\test.txt");	
	while(fi.get(c)){ //while(getline(in_file, line)) out_file << line << endl;
		if(c != '\n') c = 255 - c; //encryption.
		fo.put(c);
	}
	fi.close();
	fo.close();
	cout << endl << "File is copied." << endl;
	
	return 0;
}