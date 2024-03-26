#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int N, app,ris = 0, stileMaggiore = INT32_MIN, stileMinore = INT32_MIN, posMaggiore = 0, posMinore = 0;
    cin >> N;
    cin >> stileMaggiore;
    stileMinore = stileMaggiore;

    for (int i = 1; i < N; i++)
    {
        cin >> app;
        if (abs(app-stileMinore) + i - posMinore > ris)
        {
            ris = abs(app-stileMinore) + i - posMinore;
        }
        if (abs(app-stileMaggiore) + i - posMaggiore > ris)
        {
            ris = abs(app-stileMaggiore) + i - posMaggiore;
        }
        if (stileMinore > app + i-posMinore)
        {
            stileMinore = app;
            posMinore = i;
        }
        if (stileMaggiore + i-posMaggiore < app)
        {
            stileMaggiore = app;
            posMaggiore = i;
        }
    }

    cout << ris;

    return 0;
}