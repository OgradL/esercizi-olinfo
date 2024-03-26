#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void Vernicia(int indice, int colore);

void Diversifica(int N, int colore[]){
	unordered_map<int, int> count;
	vector<int> pos;
	for (int i = 0; i < N; i++){
		count[colore[i]]++;
		if (count[colore[i]] > 1) pos.push_back(i);
	}
	int color = 1;
	for (int i = 0; i < pos.size(); i++){
		while (count[color] != 0) color++;
		count[color]++;
		Vernicia(pos[i], color);
	}
}