#include <bits/stdc++.h>

using namespace std;
bool x[101];
int main(){
	#ifdef EVAL
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

	int N;
	cin>>N;
	
	int v[N];
	for(int i=0;i<N;i++){
		cin>>v[i];
		x[v[i]]=1;
	}
	int sum=0;
	int j=0;
	for(int i=0;i<N;i++){
		sum=v[i];
		while(sum<100){
			x[sum+v[j]]=1;
			
			
			j++;
			if(j==N){
				j=0;
				sum+=v[i];
			}
		}
	}
	for(int i=99;i>=0;i--){
		if(x[i]==0){
			cout<<i;
			return 0;
		}
	}

}
