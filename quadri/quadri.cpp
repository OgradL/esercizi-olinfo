#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isValid(vector<ll> arr, ll N, ll K, ll M){
    
    ll sum = 0;
    
    for (ll i = 0; i < K; i++){
        sum += arr[i];
    }
    ll maximum = sum;
    for (ll i = 0; i < N - K; i++){
        sum -= arr[i];
        sum += arr[i + K];
        maximum = max(maximum, sum);
    }
    
    if (maximum > M){
        return false;
    } else {
        return true;
    }
    
}


int search(vector<ll> arr, int lo, int hi, ll N, ll M){
    
    if (lo + 1 >= hi){
    	//cout << lo << " " << hi << "\n";
        return lo;
    }
    
    int mid = ll((lo + hi) / 2);
    
    if (isValid(arr, N, mid, M)){
    	return search(arr, mid, hi, N, M);
	} else {
		return search(arr, lo, mid, N, M);
	}
	
}

int binary_search(int lo, int hi, int x, vector<int>& arr){
	
	if (lo + 1 >= hi){
		return lo;
	}
	
	int mid = (lo + hi) / 2;
	
	if (qualcosa){
		return binary_search(mid, hi, x, arr);
	} else {
		return binary_search(lo, mid, x, arr);
	}
	
}


int quadri(int N, long long M, int V[]) {
    vector<ll> A(N);
	for (int i = 0; i < N; i++){
    	A[i] = V[i];
	}
	int B = search(A, 0, N + 1, N, M);
    return B;
}




int main(){
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int N;
	ll M;
    
    cin >> N >> M;
    
    
    int V[200000];
    
    for (ll i = 0; i < N; i++){
        cin >> A[i];
    }
    
    
    cout << quadri(N, M, V);
    
    
    return 0;
}
