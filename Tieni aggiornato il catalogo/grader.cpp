#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, int> mappa;


void aggiungi(long long int id) {
    mappa[id] = mappa[id] + 1;
}

void togli(long long int id) {
    mappa[id] = mappa[id] - 1;
}

int conta(long long int id) {
    return mappa[id];
}


int main() {
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        char t;
        long long int id;
        cin >> t >> id;

        if(t == 'a') {
            aggiungi(id);
        } else if (t == 't') {
            togli(id);
        } else if (t == 'c') {
            cout << conta(id) << '\n';
        }
    }

    return 0;
}
