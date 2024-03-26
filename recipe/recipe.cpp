//Scrivi qui il tuo codice
/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>
#include <vector>

using namespace std;

// input data
int N, M;
vector<vector<double>> P;
vector<double> R;

int main() {
//  uncomment the following lines if you want to read/write from files
  freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);

    cin >> N >> M;
    P.resize(N);
    R.resize(N);
    for (int i=0; i<N; i++)
        P[i].resize(M);
    for (int j=0; j<M; j++)
        for (int i=0; i<N; i++)
            cin >> P[i][j];
    
    vector<double> mol;
    mol.resize(M);
    
    for (int i = 0; i < M; i++){
        int tot = 0;
        for (int j = 0; j < N; j++){
            tot += P[j][i];
        }
        mol[i] = (1E6 / tot);
        for (int j = 0; j < N; j++){
            P[j][i] *= mol[i];
        }
    }
    
    /*for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cout << P[j][i] << " ";
        }
        cout << "\n";
    }*/
    
    for (int i = 0; i < N; i++){
        double sum = 0;
        for (int j = 0; j < M; j++){
            sum += double(P[i][j]);
            //cout << (P[i][j]) << "\n";
        }
        //cout << sum << " " << M << " ";
        //sum /= M;
        //cout << sum << "\n";
        R[i] = double(sum / M);
    }
    
    
    
    for (int i=0; i<N; i++)
        cout << (int)R[i] << " "; // print the result
    cout << endl;
    return 0;
}

/*



4 2
400000 50000 10000 40000
600000 200000 60000 140000


4 1
400000 50000 10000 40000


1 1
400000

*/