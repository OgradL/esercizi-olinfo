#include <bits/stdc++.h>

using namespace std;

struct node{
	int label;
	int index;
	vector<int> childs;
	vector<int> beauties;
	int finalBeauty;
	
	node(){
		// cool
	}
	
	vector<int> get_beauty(vector<node>& nodes, int N){
		
		if (beauties.size() != 0) return beauties;
		
		vector<int> arr(1, label);
		
		for (int c: childs){
			node child = nodes[c];
			
			vector<int> news = child.get_beauty(nodes, N);
			
			arr.insert(arr.end(), news.begin(), news.end());
			
		}
		
		beauties.insert(beauties.begin(), arr.begin(), arr.end());
		
		vector<int> count(N, 0);
		
		for (int i = 0; i < beauties.size(); i++){
			count[beauties[i]]++;
		}
		int num = 0;
		for (int i = 0; i < N; i++){
			if (count[i] > count[num]){
				num = i;
			}
		}
		
		finalBeauty = num;
		
		return beauties;
	}
	
};



int main(){
	
	int N;
	
	cin >> N;
	
	vector<int> p(N), a(N);
	
	vector<node> nodes(N);
	
	for (int i = 1; i < N; i++){
		cin >> p[i];
		nodes[p[i]].childs.push_back(i);
	}
	for (int i = 0; i < N; i++){
		cin >> a[i];
		nodes[i].label = a[i];
		nodes[i].index = i;
	}
	
	nodes[0].get_beauty(nodes, N);
	
	for (int i = 0; i < N; i++){
		cout << i << " -> " << nodes[i].finalBeauty << " <- ";
		for (int j = 0; j < nodes[i].beauties.size(); j++){
			cout << nodes[i].beauties[j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	
	return 0;
}
