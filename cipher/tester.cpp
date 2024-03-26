#include <iostream>
#include <functional>
using namespace std;

int main(int argc, char** argv){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N = 3;
	if (argc > 1){
		N = stoi(argv[1]);
		// cout << argc << " " << argv[0] << " " << argv[1] << "\n";
	}

	function<void(string&, int)> words = [&](string& s, int c){
		if (c >= N){
			cout << s << "\n";
			return;
		}
		for (int i = 'a'; i <= 'z'; i++){
			s.push_back(i);
			words(s, c+1);
			s.pop_back();
		}
	};

	string s = "";
	words(s, 0);

	return 0;
}