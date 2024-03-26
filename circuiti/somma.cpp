#include <iostream>
#include <vector>
using namespace std;

void somma(string reg1, int idx1, string reg2, int idx2, string outreg, int outidx){
	string s1, s2, s3;
	if (reg1 == "")
		s1 = to_string(idx1);
	else
		s1 = reg1 + "[" + to_string(idx1) + "]";
	
	if (reg2 == "")
		s2 = to_string(idx2);
	else
		s2 = reg2 + "[" + to_string(idx2) + "]";
	
	s3 = outreg + "[" + to_string(outidx) + "]";
	
	printf("%s = %s + %s", outreg.c_str(), s1.c_str(), s2.c_str());
	// printf("%s[%d] = %s[%d] + %s[%d]\n", outreg.c_str(), outidx, reg1.c_str(), idx1, reg2.c_str(), idx2);
}

void design_somma(int N){

	vector<int> indexes;
	int idx = 0;
	for (int i = 0; i < N; i+=2){
		somma("in", i, "in", i+1, "somma", idx++);
		indexes.push_back(idx-1);
	}
	if (N&1){
		somma("in", N-1, "", 0, "somma", idx++);
		indexes.push_back(idx-1);
	}

	



}

int main(){

	int T, N, C;
	cin >> T >> N >> C;

	if (T == 1){
		design_somma(N);
	} else {
		cout << "wrong input\n";
	}

	return 0;
}