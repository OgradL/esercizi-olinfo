template<typename T>
T max(T a, T b){
	if (a > b)
		return a;
	return b;
}

long long f(int V[], int mid, int N){
	long long sum = 0, ma = 0;
	for (int i = 0; i < mid; i++){
		sum += V[i];
	}
	ma = sum;
	for (int i = 0; i < N - mid; i++){
		sum -= V[i];
		sum += V[i + mid];
		ma = max(ma, sum);
	}
	return ma;
}

int quadri(int N, long long M, int V[]) {
	int lo = 0, hi = N+1, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		if (f(V, mid, N) <= M){
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return lo;
}