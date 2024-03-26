#include <iostream>
using namespace std;

int main(int argc, char** argv){

	FILE *f1, *f2;

	string com = "generator " + to_string(stoi(argv[1])) + " " + to_string(stoi(argv[2])) + " > input.txt";
	system(com.c_str());
	system("git < input.txt > output1.txt");
	system("git_non_implicit < input.txt > output2.txt");


	f1 = fopen("output1.txt", "r");
	f2 = fopen("output2.txt", "r");


	int n1, n2, count = 0;
	while (fscanf(f1, "%d", &n1) != EOF && fscanf(f2, "%d", &n2) != EOF){
		if (n1 != n2){
			count++;
		}
	}

	cout << count << " errors\n";

	return 0;
}