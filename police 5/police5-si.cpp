#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 10001
using namespace std;

// input data
int N, M, T;
vector<pair<int, int> > adj[MAXN];
vector<pair<int, int> > bdj[MAXN];
long long dist[MAXN];
int visto[MAXN];

void dijkstra(int inizio,int fine){
	int u;
	for(u=0; u<=N; u++) dist[u]=1e18;
	dist[inizio]=0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0,inizio));
	while(!pq.empty()){
		int s=pq.top().second;
		pq.pop();
		if(s==fine) break;
		if(visto[s]) continue;
		visto[s]=1;
		
		for(u=0;u<adj[s].size();u++){
			int next = adj[s][u].second;
			int Peso = adj[s][u].first;
			
			if(dist[s]+Peso<dist[next] && ((T-(dist[s]+Peso)>=0) || bdj[s][u].first==0)){
				dist[next] = dist[s]+Peso;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
	
}
int main() {
//  uncomment the following lines if you want to read/write from files
  ifstream cin("input.txt");
  ofstream cout("output.txt");
	int A,B,C,E,i;
    cin >> N >> M >> T;
    for (i=0; i<M; i++){
    	cin >> A >> B >> C >> E;
    	adj[A].push_back(make_pair(C,B));
    	bdj[A].push_back(make_pair(E,B));
	}
        
	dijkstra(0,N-1);
	if(dist[N-1]==1000000000000000000) dist[N-1]=-1;
    cout << dist[N-1] << endl; // print the result
    return 0;
}