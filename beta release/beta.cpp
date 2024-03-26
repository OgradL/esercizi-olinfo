#include <stdio.h>
#include <unordered_map>
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops")

int N;
std::unordered_map<int, int> m;
int main() {
	FILE *fr, *fw;
	fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    
    fscanf(fr, "%d", &N);

    int curr, mu = 0;
    for (int i = 0; i < N; i++){
        fscanf(fr, "%d", &curr);
        
        m[curr]++;
        if (m[curr] == 2) {
			mu++;
			if (mu > 1) break;
		}
    }
    
    if (mu >= 2){
        fprintf(fw, "%s\n", "YES");
    } else {
        fprintf(fw, "%s\n", "NO");
    }

	fclose(fr);
    fclose(fw);
    return 0;
}