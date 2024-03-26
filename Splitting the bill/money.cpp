#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n_people, n_transfers;
    cin >> n_people >> n_transfers;
    
    unordered_map<int, int> lent;
    for (int i = 0; i < n_people; i++)
        lent[i] = 0;
    
    for (int i = 0; i < n_transfers; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
		
        lent[from] -= weight;
        lent[to] += weight;
    }
	
    int payments = 0;
    for (int i = 1; i < n_people; i++)
        if (lent[i] != 0)
            payments++;
    
    cout << payments << '\n';
	
    for (int i = 1; i < n_people; i++)
    {
        if (lent[i] > 0)
            cout << i << ' ' << 0 << ' ' << lent[i] << '\n';
        else if (lent[i] < 0)
            cout << 0 << ' ' << i << ' ' << -lent[i] << '\n';
    }
}
