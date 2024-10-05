#include <iostream>
#include <vector>

long long alleggerisci(int N, int M, std::vector<int> V, std::vector<int> L, std::vector<int> R, std::vector<long long> K);

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> V(N), L(M), R(M);
    std::vector<long long> K(M);

    for (int &x: V) {
        std::cin >> x;
    }

    for (int i = 0; i < M; i++) {
        std::cin >> L[i] >> R[i] >> K[i];
    }

    std::cout << alleggerisci(N, M, V, L, R, K) << '\n';

    return 0;
}
