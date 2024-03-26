#include <iostream>
#include <vector>

#include "disegno.h"

int main() {
    int N;
    int L;
    std::cin >> N >> L;

    std::vector<Point> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        int Ax, Ay, Bx, By;
        std::cin >> Ax >> Ay >> Bx >> By;
        A[i] = Point{Ax, Ay};
        B[i] = Point{Bx, By};
    }

    std::vector<Point> moves = draw(N, L, A, B);

    std::cout << moves.size() << std::endl;
    for (Point P : moves) {
        std::cout << P.x << " " << P.y << std::endl;
    }
}
