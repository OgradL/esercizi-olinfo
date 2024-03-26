//Scrivi qui il tuo codice
#include <bits/stdc++.h>

using namespace std;

struct arc{
    int A;
    int B;
    int t;
    
    arc(){}
    
    arc(int a, int b, int c){
        A = a;
        B = b;
        t = c;
    }
    
    
};

void f(int node, int d, vector<vector<arc> >& G, vector<int>& P){
    
    //cout << node << " - " << d << "\n";
    
    P[node] = d;
    
    for (int i = 0; i < G[node].size(); i++){
        
        arc arco = G[node][i];
        
        if (P[arco.B] > d + arco.t){
            f(arco.B, d + arco.t, G, P);
        }
        
    }
    
    
    
    
}


int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    int N, SB, SN;
    
    cin >> N >> SN >> SB;
    
    vector<vector<arc> > G(N);
    
    int A, B;
    
    //cerr << "yay\n";
    
    for (int i = 0; i < SN; i++){
        //cerr << "yay1 " << i << "\n";
        cin >> A >> B;
        
        A--;
        B--;
        
        G[A].push_back(arc(A, B, 0));
        
        G[B].push_back(arc(B, A, 0));
    }
    
    for (int i = 0; i < SB; i++){
        //cerr << "yay2 " << i << "\n";
        cin >> A >> B;
        
        A--;
        B--;
        
        G[A].push_back(arc(A, B, 1));
        
        G[B].push_back(arc(B, A, 1));
    }
    //cerr << "yay1 " << "hd" << "\n";
    vector<int> P(N, INT_MAX);
    
    //cerr << "yay\n";
    
    f(0, 0, G, P);
    
    cout << P[N - 1] << "\n";
    
}

/*

7 1 11
1 5
3 5
4 3
4 6
1 2
2 3
3 1
1 6
5 6
5 4
4 7
6 7



8 5 9
1 5
3 5
4 3
4 6
7 8
1 2
2 3
3 1
1 6
5 6
5 4
4 8
6 8
6 7




*/