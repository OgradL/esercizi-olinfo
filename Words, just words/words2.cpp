//Scrivi qui il tuo codic
#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int modulo = 1000000007,ris = 0;
    char app;
    long long int potenze = 1;
    string parola;
    cin>>parola;
    for(int i = parola.size()-1; i >= 0; i--)
    {
        char app = parola[i];
        int valore = (int)parola[i] - 96;
        ris = (ris + (valore*potenze)%modulo)%modulo;
        potenze = (potenze * 26)%modulo;
    }

    cout<<ris-1;
    return 0;
}