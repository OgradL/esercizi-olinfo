#include <bits/stdc++.h>
#include <sstream>

using namespace std;

#define BLEAH false
#define SLURP true

struct path{
	
	int N = -1;
	string percorso = "nop";
	
};

path search(int node, bool status, vector<vector<int> >& graph, vector<short int>& last){
	
	if (status){
		last[node] = 1;
	} else {
		last[node] = 0;
	}
	
	if (node == 0 && status){
		path perc;
		perc.N = 1;
		perc.percorso = "0";
		return perc;
	}
	
	
	for (int i = 0; i < graph[node].size(); i++){
		
		int newNode = graph[node][i];
		
		if (last[newNode] >= 0){
			if ((status && last[newNode] == 1) || (!status && last[newNode] == 0)){
				
				path a = search(newNode, !status, graph, last);
				
				if (a.N != -1){
					a.N++;
					
					string st;
					ostringstream temp;
					temp << node;
					st = temp.str();
					
					a.percorso = st + " " + a.percorso;
					return a;
				}
				
			}
		} else {
			path a = search(newNode, !status, graph, last);
			if (a.N != -1){
				a.N++;
				
				string st;
				ostringstream temp;
				temp << node;
				st = temp.str();
				
				a.percorso = st + " " + a.percorso;
				return a;
			}
		}
		
		
	}
	
	path ans;
	
	return ans;
}


int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int N, M;
	
	cin >> N >> M;
	
	vector<vector<int> > graph(N, vector<int>(0));
	
	for (int i = 0; i < M; i++){
		int A, B;
		
		cin >> A >> B;
		
		graph[A].push_back(B);
		
		graph[B].push_back(A);
		
	}
	
//	vector<bool> visited(N, false);
//	vector<bool> last(N, false);
	vector<short int> last(N, -1);
	
	path ans = search(0, BLEAH, graph, last);
	
	cout << ans.N - 1 << "\n" << ans.percorso << "\n";
	
	return 0;
}
