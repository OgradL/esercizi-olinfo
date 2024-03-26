/*
 * Author: Enea Scaccabarozzi
 * Date: 2022-03-14
 * Problem: Do Not Gather!
 * Reference: https://training.olinfo.it/#/task/ois_gatherings/statement
 */

#include <iostream>
using namespace std;

// constraints
#define MAXN 100000

// input data
int N, D, i;
int P[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
  freopen("input1.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

    cin >> N >> D;
    for(i=0; i<N; i++)
        cin >> P[i];

    long long answer = 0;
    int i=0;
    int j=1;
    while (i<N-1)
    {
        if(P[j] - P[i] >= D || j >= N )
        {
            answer += j-i-1;
            i++;
        } else 
            j++;
    }
    cout << answer << endl; // print the result
    return 0;
}
