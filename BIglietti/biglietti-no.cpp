//Scrivi qui il tuo codic
#include <fstream>


int main() { // 100/100
    std::ifstream cin("input.txt", std::ios::in);
    std::ofstream cout("output.txt", std::ios::out);
    std::ios_base::sync_with_stdio(false);

    long long int N, M, A, B, C=0;
    cin >> N >> M >> A >> B;

    while (N) {
      if (N >= M) {
        if (B <= A*M) {
          N -= M;
          C += B;
        } else {
          N--;
          C += A;
        }
      } else {
        if (B >= A*N)
          C += A*N;
        else
          C += B;
        break;
      }
    }

    cout << C;
}