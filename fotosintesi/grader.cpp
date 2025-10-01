#include <iostream>
using namespace std;

int fotosintesi (int N, string S);

int main () {

    string S; cin >> S;

    cout << fotosintesi(S.size(), S) << endl;
}
