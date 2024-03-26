#include <unordered_map>
using namespace std;

unordered_map<long long, int> mappa;

void aggiungi(long long id) {
    mappa[id] = mappa[id] + 1;
}

void togli(long long id) {
    mappa[id] = mappa[id] - 1;
}

int conta(long long id) {
    return mappa[id];
}

