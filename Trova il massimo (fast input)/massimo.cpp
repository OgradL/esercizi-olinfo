#include <stdio.h>

using namespace std;

int main() {
    FILE *fr, *fw;
    long long int N;
    long long int current = 0;
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    long long ans = LLONG_MIN;
    for(long long i = 0; i < N; i++){
        assert(1 == fscanf(fr, "%lld", &current));
        if (current > ans){
        	ans = current;
		}
    }
    
    fprintf(fw, "%d ", ans);
	
    fclose(fr);
    fclose(fw);
    return 0;
}
