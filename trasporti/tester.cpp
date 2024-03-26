#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
using namespace std;

int main(int argc, char ** argv){
	srand(time(NULL));

	int total_tests = stoi(argv[4]);
	for (int test = 1; test <= total_tests; test++){
		
		int N = 1000, Q = 1000;
		vector<pair<int, int>> queries;
		vector<int> br;

		if (argc >= 4 && argv[1][0] == '1'){
			ofstream out("output.txt");

			N = stoi(argv[2]), Q = stoi(argv[3]);
			out << N << " " << Q << "\n";

			br.resize(N);
			for (int i = 0; i < N; i++){
				br[i] = rand() % 10000;
				out << br[i] << " ";
			}
			out << "\n";

			for (int i = 0; i < N - 1; i++){
				out << i << " " << i + 1 << "\n";
			}

			queries.resize(Q);
			for (int i = 0; i < Q; i++){
				queries[i] = {rand() % N, rand() % N};
				if (queries[i].first > queries[i].second)
					swap(queries[i].first, queries[i].second);
				out << queries[i].first << " " << queries[i].second << "\n";
			}

			out.close();
		} else {
			ifstream in("output.txt");
			in >> N >> Q;
			
			br.resize(N);
			for (int i = 0; i < N; i++){
				in >> br[i];
			}

			int d;
			for (int i = 0; i < N-1; i++){
				in >> d >> d;
			}
			
			queries.resize(Q);
			for (int i = 0; i < Q; i++){
				in >> queries[i].first >> queries[i].second;
			}

			in.close();
		}

		system("trasporti < output.txt > out.txt");

		ifstream in("out.txt");

		int res;
		for (int i = 0; i < Q; i++){
			in >> res;
			int ans = 0;
			for (int j = queries[i].first; j <= queries[i].second; j++)
				ans = max(ans, br[j]);
			
			if (res != ans){
				cout << "no at query " << i << "\n";
				cout << "found " << res << " instead of " << ans << "\n";
				cout << "query:\n" << queries[i].first << " " << queries[i].second << "\n";
				cout << br[0] << " " << br[queries[i].first] << " " << br[queries[i].second] << "\n";
				return 1;
			}
		}

		in.close();
		cout << "\r" << (test * 100 / total_tests) << "% ( " << test << " / " << total_tests << " )" << flush;
	}
	cout << "\n";

	return 0;
}