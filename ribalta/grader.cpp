#include <string>
#include <iostream>
using namespace std;

int ribalta(int N, string S);

int main(void) {
    int N; cin >> N;

    string S; cin >> S;

    cout << ribalta(N, S) << endl;
}
