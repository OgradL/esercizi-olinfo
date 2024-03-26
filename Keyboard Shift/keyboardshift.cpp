// NOTE: it is recommended to use this even if you don't understand the
// following code.
#include<cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// input data

const char Letters[] = "qwertyuiopasdfghjklzxcvbnm";

int GetIndex(char letter)
{
    for (int i = 0;i<strlen(Letters);i++)
        if(letter == Letters[i])
            return i;
    return -1;
}

int N;
string S;

int main() {
    
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    cin >> S;

   
    for(int i = 0;i<N;i++)
    {

            int index = GetIndex(S[i]);
            S[i] = Letters[index+1];
    }


    

    cout << S << endl; // print the result
    return 0;
}
