#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    
    ifstream cin("input.txt");
    ofstream cout("output.txt");
	
    long long A, B, T;
    cin >> A >> B >> T;

    long long int down;
    long long int sub;
    
    T -= (24 - B);
    sub = (long long int)(T / 24);
    T -= sub * 24;
    down = (sub * (B - A));
    
    if (T < A){
    } else if (T >= A && T < B){
        down += (T - A);
    } else {
        down += (B - A);
    }

    cout << down << endl;
    
    return 0;
}
