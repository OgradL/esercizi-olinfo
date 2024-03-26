# define MAXN 1500000

int N ;
int A[MAXN], ord[MAXN], fen[MAXN];

int ask(int i) {
    int res = 0;
        for (; i >= 0; i = (i&(i+1)) -1) res += fen[i];
    return res;
}

void add(int i , const int N) {
    for (; i < N; i = i|(i+1)) fen[i]++;
}

long long Solve(int N) {
    for (int i = 0; i < N; i++) fen[i] = 0;
    for (int i = 0; i < N; i++) ord[A[i]] = i;
    long long res = 0;
    for (int i = N-1; i >= 0; i--) {
        res += ( long long )ask(ord[i]);
        add(ord[i], N);
    }
    return res;
}

long long paletta_sort(int N , int V[]) {
    // Controllo che sia possibile ordinare gli elementi
    for (int i = 0; i < N; i++) {
        if (V[i]%2 != i%2) return -1;
    }
    
    // Contare gli scambi sui due sotto - array ( pari e dispari )
    long long res = 0;
    
    for (int i = 0; i < N; i+=2) A[i/2] = V[i]/2;
    res += Solve((N+1)/2);
    
    for (int i = 1; i < N; i+=2) A[(i-1)/2] = (V[i]-1)/2;
    res += Solve(N/2);
    
    return res;
}