/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// constraints
#define MAXN 1000000

// input data
ll N;
ll P[MAXN];
ll G[MAXN];


int main() {
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	
	ll min = 0;
	ll ris = 0;
    
	cin >> N;

    for (int i = 0; i < N; i++) assert(1 == scanf("%d", &P[i]));
    for (int i = 0; i < N; i++) assert(1 == scanf("%d", &G[i]));
    
    min = P[0];
    
	for(int i = 0; i < N; i++)
	{
		if(P[i]<min)
		{
			min = P[i];
		}
		ris+= G[i]*min;
	}
	
	cout<<ris;
	
	return 0;
}
