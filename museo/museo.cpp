#include <vector>

int N;
int st[400001];

void inizia(int N, std::vector<int> A) {
	::N = N;
	for (int i = N; i < 2*N; i++)
		st[i] = A[i-N];

	for (int i = N-1; i > 0; --i)
		st[i] = std::max(st[i<<1], st[i<<1|1]);
}

void aggiorna(int P, int X) {
	for (st[P += N] = X; P > 1; P >>= 1){
		st[P >> 1] = std::max(st[P], st[P ^ 1]);
	}
}

int massimo(int L, int R) {
	int ans = 0;
	for (L += N, R += N+1; L < R; L >>= 1, R >>= 1){
		if (L & 1) ans = std::max(ans, st[L++]);
		if (R & 1) ans = std::max(ans, st[--R]);
	}
	return ans;
}
