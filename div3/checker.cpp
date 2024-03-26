#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){

	// FILE *f1, *f2;

	string com = "generator " + to_string(stoi(argv[1])) + " " + to_string(stoi(argv[2])) + " > input.txt";
	system(com.c_str());
	system("div3 < input.txt > output1.txt");
	system("div3-meglio < input.txt > output2.txt");

	ifstream f1("output1.txt");
	ifstream f2("output2.txt");

	f1.tie(0);
	f1.sync_with_stdio(false);
	f2.tie(0);
	f2.sync_with_stdio(false);
	// f1 = fopen("output1.txt", "r");
	// f2 = fopen("output2.txt", "r");

	string n1, n2;
	int count = 0;
	while ((f1 >> n1) && (f2 >> n2)){
		if (n1 != n2){
			cout << n1 << " " << n2 << "\n";
			count++;
		}
	}

	cout << count << " errors\n";

	return 0;
}