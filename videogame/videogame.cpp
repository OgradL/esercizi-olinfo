#include <iostream>
#include <queue>
using namespace std;

#define type second
#define time first


int main(int argc, char** argv){

	if (argc > 1){
		freopen(argv[1], "r", stdin);
	}

	int T, N, M, a, b;
	cin >> T;

	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		pq.push({a, 0});
		pq.push({b, 2});
	}
	cin >> M;
	for (int j = 0; j < M; j++){
		cin >> a >> b;
		pq.push({a, 1});
		pq.push({b, 3});
	}

	int ans = 0;

	pair<int, int> event;
	int ajoined = -1, bjoined = -1, both = 0, togethersince = 0;
	while (!pq.empty()){
		event = pq.top();
		pq.pop();

		// player 1 joins
		if (event.second == 0){
			ajoined = event.first;
			if (bjoined != -1){
				togethersince = event.first;
				both = 1;
			}
		}
		// player 1 quits
		if (event.second == 2 && ajoined != -1){

			if (both){
				// cout << "together: " << togethersince << " to " << event.time << " total " << event.time - togethersince + 1 << "\n";
				ans += event.time - togethersince + 1;
			}

			ajoined = -1;
			both = 0;
			togethersince = 0;
		}
		// player 2 joins
		if (event.second == 1){

			if (ajoined != -1 && event.time - ajoined > T){
				ajoined = -1;
				both = 0;
			}

			bjoined = event.first;
			if (ajoined != -1){
				togethersince = event.time;
				both = 1;
			}
		}
		// player 2 quits
		if (event.second == 3){

			if (both){
				// cout << "together: " << togethersince << " to " << event.time << " total " << event.time - togethersince + 1 << "\n";
				ans += event.time - togethersince + 1;
				ajoined = event.time + 1;
			}

			bjoined = -1;
			both = 0;
			togethersince = 0;
		}

		// cout << event.first << " " << event.second << " | " << ajoined << " " << bjoined << " " << both << " " << togethersince << "\n";
	}


	cout << ans << "\n";

	return 0;
}