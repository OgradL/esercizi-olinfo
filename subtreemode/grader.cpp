#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> solve(int n, vector<int> p, vector<int> a);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//ifstream ("input0.txt", "r");
	
	int n;
	cin >> n;
	vector<int> p(n), a(n);
	for (int v = 1; v < n; v++) cin >> p[v];
    for (int v = 0; v < n; v++) cin >> a[v];
    
    //vector<int> prova(1, 3);
    //cout << prova[0] << endl;
    
    //solve(n, p, a);
    //vector<int> res(n);
    vector<int> res = solve(n, p, a);
    for (int v = 0; v < n; v++) cout << res[v] << " ";
    cout << "\n";
}
