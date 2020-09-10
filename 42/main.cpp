//42- Stream (File Stream)

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream in_file; //{"path.filename.extension"}
	ofstream out_file; //{"path.filename.extension"}
	string s1;
	int i1;
	double d1;
	string line;
	char c{};
	
	in_file.open("D:\\CPP_Workspace\\build-Debug\\bin\\test.txt");
	if(!in_file){
		cerr << "Error: File cannot be opened for reading." << endl;
		return 1; //exit(1)
	}
	
	out_file.open("D:\\CPP_Workspace\\build-Debug\\bin\\copy.txt");
	if(!out_file){
		cerr << "Error: File cannot be opened for writing." << endl;
		return 1;
	}
	
	cout << "File is opened." << endl;
	while(!in_file.eof()){ //while(in_file >> s1 >> i1 >> d1)
		in_file >> s1 >> i1 >> d1;
		cout << s1 << ", " << i1 << ", " << d1 << endl;
	}
	in_file.close();
	cout << endl;
	
	in_file.open("D:\\CPP_Workspace\\build-Debug\\bin\\test.txt");
	while(getline(in_file, line))
		cout << line << endl;
	in_file.close();
	cout << endl;
	
	in_file.open("D:\\CPP_Workspace\\build-Debug\\bin\\test.txt");
	while(in_file.get(c)){
		if(c == '\n') c = '\t';
		cout << c;
	}
	in_file.close();
	cout << endl;
	
	in_file.open("D:\\CPP_Workspace\\build-Debug\\bin\\test.txt");
	//while(getline(in_file, line)) out_file << line << endl;
	while(in_file.get(c)){
		if(c != '\n') c = 255 - c;
		out_file.put(c);
	}
	in_file.close();
	out_file.close();
	cout << endl;
	
	return 0;
}
