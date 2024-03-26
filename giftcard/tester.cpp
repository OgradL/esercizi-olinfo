#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv){

	ofstream fileout("wrongslist.txt");
	ios_base::sync_with_stdio(false);

	int wrongs = 0, limit = 100;
	cout << "\n";
	for (int c1 = 1; c1 <= limit; c1++){
		for (int c2 = 1; c2 <= limit; c2++){
			string cmd = "giftcard " + to_string(limit) + " " + to_string(c1) + " " + to_string(c2) + " > testeroutput.txt\n";
			system(cmd.c_str());
			ifstream ans ("testeroutput.txt");
			int x1, x2;
			ans >> x1 >> x2;
			if (c1 * x1 + c2 * x2 != limit){
				wrongs++;
				fileout << limit << " " << c1 << " " << c2 << " " << x1 << " " << x2 << "\n";
			}
			ans.close();
			cout << "\r " << setprecision(2) << fixed << double((c1-1)*limit+c2) / (limit*limit) * 100 << "% completed - " << wrongs << " wrongs";
			if (rand() % 1000)
				cout << flush;
		}
	}

	return 0;
}