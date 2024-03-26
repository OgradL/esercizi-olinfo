#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// input data
int N, i;
vector<int> D;
bool stop = false;

int main() {

  ifstream cin("input.txt");
  ofstream cout("output.txt");

    cin >> N;
    D.resize(N);
    for (i=0; i<N; i++)
        cin >> D[i];
	
	//int arr[] = {1, 2, 3};
	//int n = sizeof(arr) / sizeof(arr[0]);
	
	sort(D.begin(), D.end());
	
    for (i = 0; i < N - 1; i++){
        
        /*if (!stop)
        for (int j = 0; j < i; j++){
            
            if (j == i){
                continue;
            }
            
            if (D[i] == D[j]){
                stop = true;
                break;
            }
            
        }*/
        
        if (D[i] == D[i + 1]){
        	stop = true;
        	break;
		}
        
    }
    
    if (stop){
        cout << "Impossible";
    } else {
        cout << "Ok";
    }

   // cout << 42; // print the result
    return 0;
}
