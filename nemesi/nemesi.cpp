#include <iostream>
#include <vector>
using namespace std;

void nuovo_gruppo();

void aggiungi(int bambino);

void smista(int N, int nemico[]) {

	vector<vector<int>> gruppi;
	int g = 0;
	int b = 0;
	vector<int> v(N, 0);
	while (true){
		if (v[b]){
			
		}
		v[b] = 1;


	}


	for (auto x : gruppi){
		nuovo_gruppo();
		for (auto b : x){
			aggiungi(b);
		}
	}

}

