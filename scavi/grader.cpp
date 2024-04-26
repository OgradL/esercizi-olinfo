#include<bits/stdc++.h>
using namespace std;
void scavi(int R, int C, int Q, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2, vector<int> &P, vector<vector<int>> &terreno);
int main(){
	int R, C, Q;
	cin>>R>>C>>Q;
	vector<int> x1(Q), y1(Q), x2(Q), y2(Q), p(Q);
	for(int i=0;i<Q;i++)
	 	cin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>p[i];
	vector<vector<int>>t(R,vector<int>(C));
	scavi(R,C,Q,x1,y1,x2,y2,p,t);
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++)
			cout<<t[i][j]<<" ";
		cout<<endl;
	}
}
