#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

long long V[15];

long double x[15] = {0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 1, 2, 5, 10, 20, 50, 100, 200, 500};

long long soldi[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main()
{
	
	freopen("input output/input0.txt", "r", stdin);
	//freopen("input output/output0.txt", "w", stdout);
	
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 0; i < 15; i++)
    {
        scanf("%lld", &V[i]);
    }
    long double somma = 0;

    for (int i = 0; i < 15; i++)
    {
        somma += V[i] * x[i];
    }

    long long tmp = 0;
    for (int i = 14; i > -1; i--)
    {
        tmp = (long long)(somma / x[i]);
        soldi[i] = tmp;
        somma -= x[i] * soldi[i];
    }

    for (int i = 0; i < 15; i++)
        printf("%lld%s", soldi[i], " ");
    return 0;
}
