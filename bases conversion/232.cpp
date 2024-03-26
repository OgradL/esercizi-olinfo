#include <bits/stdc++.h>

using namespace std;

vector<int> pow3(20, -1);
vector<int> pow2(30, -1);


int b2(int N, int prev){
    int lo = 0, hi = 28, mid = 14;
    while (lo + 1 < hi){
        mid = (lo + hi) / 2;
        
        if (N % pow2[mid] == 0){
            lo = mid;
        } else {
            hi = mid;
        }
    }
    int ans = prev + 1 - lo;
    //cout << N << " " << ans << "\n";
    return ans;
}

int b3(int N, int prev){
    int lo = 0, hi = 18, mid = 9;
    while (lo + 1 < hi){
        mid = (lo + hi) / 2;
        
        if (N % pow3[mid] == 0){
            lo = mid;
        } else {
            hi = mid;
        }
    }
    int ans = prev + 1 - lo - lo;
    return ans;
}


int main() {
    
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    
    
    int curr = 1;
    for (int i = 0; i < 30; i++){
        pow2[i] = curr;
        curr *= 2;
    }
    curr = 1;
    for (int i = 0; i < 20; i++){
        pow3[i] = curr;
        curr *= 3;
    }
    
    
    
    
    int N;
    
    cin >> N;
    
    vector<int> num(N);
    int maxN = 0;
    
    for (int i = 0; i < N; i++){
        cin >> num[i];
        maxN = max(maxN, num[i]);
    }
    
//	vector<int> prec2(maxN + 1, -1);
//	prec2[1] = 1;
//	vector<int> prec3(maxN + 1, -1);
//	prec3[1] = 1;
    
    vector<int> copyNum = num;
    
    sort(copyNum.begin(), copyNum.end());
    
    map<int, int> answer;
    
    //vector<int> res(maxN + 1, -1);
    //res[0] = 1;
    
    int ans = 0;
    
    int prec2 = 1;
    int prec3 = 1;
    
    int numidx = 0;
    
    for (int i = 1; i <= maxN; i++){
        
        if (prec2 == prec3){
        	ans++;
//        	cout << i << "\n";
		}
        
        prec2 = b2(i+1, prec2);
        prec3 = b3(i+1, prec3);
        if (copyNum[numidx] == i){
        	answer[copyNum[numidx]] = ans;
        	numidx++;
        	while (copyNum[numidx-1] == copyNum[numidx]){
        		numidx++;
        		if (numidx > N){
        			break;
				}
			}
		}
    }
//	cout << "\n\n\n";
    
	for (int i = 0; i < N; i++){
		cout << answer[num[i]] << " ";
	}
    cout << "\n";
}
