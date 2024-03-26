#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

#define MAXN 100000

int gira(int N, char descrizione[]) {
    
    int piu = 0;
    int meno = 0;
    
    for (int i = 1; i < N; i += 4){
        //cout << descrizione[i] << "\n";
        if (descrizione[i] == '+'){
            piu++;
        } else {
            meno++;
        }
    }
    
    
    
    return min(meno, piu);
}


char descrizione[MAXN + 5]; // Maggiore di MAXN per contenere newline e null

int main() {
    FILE *fr, *fw;
    int N;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    assert(1 == scanf("%d\n", &N));
    cin >> descrizione;
    
    //assert(fgets(descrizione, MAXN + 5, fr) == descrizione);
    descrizione[N] = 0;

    printf("%d\n", gira(N, descrizione));
    //fclose(fr);
    //fclose(fw);
    return 0;
}