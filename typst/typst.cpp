#include <iostream>
using namespace std;

int compila(int D, int X, int N, int S) {
    return max(0, N - (D - X) / S);
}
