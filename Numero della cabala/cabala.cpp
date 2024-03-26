//Scrivi qui il tuo codice
#include <bits/stdc++.h>
#include <stdio.h>
#include <assert.h>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;

int solve(ull num, int N, int M, ull po){
    
//	cout << num << "\n";
    
	if (num >= po) return 0;
    
    int ans = int(num % M);
    
    int last = num % 10;
    
    if (last != 3)
        ans = max(ans, solve(num * 10 + 3, N, M, po));
    
    if (last != 6)
        ans = max(ans, solve(num * 10 + 6, N, M, po));
    
    if (last != 9)
        ans = max(ans, solve(num * 10 + 9, N, M, po));
    
    return ans;
}

int main() {
    FILE *fr, *fw;
    int T, N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        int ans = 0;
        ull po = 1;
        for (int i = 0; i < N; i++){
        	po *= 10;
		}
        ans = max(ans, solve(3, N, M, po));
        
        ans = max(ans, solve(6, N, M, po));
        
        ans = max(ans, solve(9, N, M, po));
        fprintf(fw, "%d ", ans);
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
