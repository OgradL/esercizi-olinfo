#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(){
	
	ifstream f0("input_bonus.txt");
	ifstream f1("output_bonus.txt");
	ifstream f2("output_bonus1.txt");
	
	int N, Q;
	
	f0 >> N >> Q;
	int outputs = 0, a, b, c;
	for (int i = 0; i < Q; i++){
		f0 >> a >> b >> c;
		if (a == 1) outputs++;
	}
	
	bool correct = true;
	int ans1, ans2;
	for (int i = 0; i < outputs; i++){
		f1 >> ans1;
		f2 >> ans2;
		correct = correct && (ans1 == ans2);
		if (!correct){
			cout << i << "\n";
			break;
		}
	}
	
	if (correct){
		cout << "good!";
	} else {
		cout << "not good!";
	}
	
	return 0;
}
