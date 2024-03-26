#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main(int argc, char** argv){
	srand(time(NULL));

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N = 1000;
	if (argc > 1)
		N = stoi(argv[1]);
	cout << N << "\n";

	for (int i = 0; i < N; i++)
		cout << 1 << " ";
	cout << "\n";
}