#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void organizza(int N, string T);
int  sfida(int a, int b);
void allea(int a, int b);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, Q; cin >> N >> Q;

    string S; cin >> S;

    organizza(N, S);

    int allea_cnt = 0;
    int sfida_cnt = 0;
    while(Q--) {
        int t, a, b; cin >> t >> a >> b;

        if(t == 2)
            allea(a, b);
        else if(t == 1)
            cout << sfida(a, b) << "\n";
        else assert(0);
    }
}
