#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define mod 1000000007
/*
	elencherò qua in breve le competenze richieste per risolvere questo problema, per le persone
	a cui interessa:
	segment tree o binary indexed tree per processare le queri velocemente
	binary coefficient https://en.wikipedia.org/wiki/Binomial_coefficient la sezione su
	combinatorics and statistics (there are (n+k-1 , k) ways to choose...)
	per calcolare velocemente il binary coefficient modulo m usare la proprietà degli inversi
	modulari (io in questo caso o usato un codice "prefatto" e non ne ho scritto uno mio
*/


using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
// input data
int N, Q, K, type,factorial[2000001];
vector<int> V;
/*int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of 
    // recursive call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
int modinv(int a){
	int x, y;
	int g = gcdExtended(a, mod, &x, &y);
	return (x % mod + mod) % mod;
}*/
int modinv(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    in >> N >> Q >> K;
    V.resize(2*N);
    for (int i=N; i<2*N; i++){
        in >> V[i];
        V[i]=max(V[i],K);
	}
	factorial[0]=1;
	for(int i=1;i<=2000000;i++)factorial[i]=(long long)factorial[i-1]*i%mod;
	for (int i=N-1;i>0;i--)V[i]=(V[i<<1]+V[i<<1|1]);
	//for(int i=1;i<N*2;i++)cout<<V[i]<<" ";
	//cout<<endl;
    for (int i=0; i<Q; i++) {
        in >> type;
        if (type == 1) {
            //cout<<"type 1"<<endl;
            // building update
            int a, b;
            in >> a >> b;
            a+=N-1;
			V[a]=max(b,K);
			for (a/=2;a>=1;a/=2)V[a]=(V[2*a]+V[2*a+1]);
			//for(int i=1;i<N*2;i++)cout<<V[i]<<" ";
			//cout<<endl;
        }
        if (type == 2) {
            //cout<<"type 2"<<endl;
            // redevelopment planning
            int l, r, s,tot,result;
            in >> l >> r >> s;
        	tot=r-l+1;
        	//cout<<s<<" "<<tot<<" after: ";
			l+=N-1;	r+=N-1;
			while(l<=r){
				if(l%2==1)s-=V[l++];
				if(r%2==0)s-=V[r--];
				l/=2;	r/=2;
			}
		    s+=tot-1;tot--;
		    if(s-tot+1>0)result=(long long)factorial[s]*modinv((long long)factorial[s-tot]*factorial[tot]%mod,mod)%mod;
		    else result=0;
		    //if(tot==0)result=1;
		    out<<result<<endl;
			//cout<<s<<" "<<tot<<" "<<result<<" "<<" "<<endl;
        }
    }
    return 0;
}
