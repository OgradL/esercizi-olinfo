#include <stdio.h>
#include <assert.h>
#include <iostream>


using namespace std;

// constraints
#define MAXN 100000
#define MAXW 21


int N, K, i;
char W[MAXN][MAXW];

int main() {
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    //scanf("%d%d", &N, &K);
    cin >> N;
    cin >> K;
    
    int countLetter[MAXN];
    
    for (i = 0; i < N; i++){
        //scanf("%s", W[i]));
        cin >> W[i];
        for (int u = 0; W[i][u] != '\0'; u++){
            countLetter[i]++;
        }
        
        //cout << W[i] << " " << countLetter[i] << "\n";
        //cout << "hehe\n";
    }
        
    char out[MAXN];
    int currentChar = 0;
    int temp = currentChar;
    
    
    
    
    for (int i = 0; i < N; i++){
        
        //cout << "\n" << i + 1 << " looop\n";

		if (currentChar + countLetter[i] > K){
			currentChar = 0;
			//cout << "limite\n";
		    for (int u = 0; u < countLetter[i]; u++){
			    //cout << out[u];
		    }
		    //cout << "\n";
		    //cout << "\n";
		    cout << out << "\n";
			//printf("%s\n", out);
		}
		
		temp = currentChar;
		
		for (int y = currentChar; y < temp + countLetter[i]; y++){
			out[y] = W[i][y - temp];
			//cout << "ho scritto " << out << " " << out[y] << "\n";
			currentChar++;
		}
		
		for (int r = currentChar; r <= K + 1; r++){
		    
		    out[r] = '\0';
		    
		}
		out[currentChar] = ' ';
        currentChar++;
        
        
        //cout << out;
        
    }
    
    cout << out << "\n";
	
    return 0;
}
