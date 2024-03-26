#include <iostream>
#include <map>
using namespace std;

int main(){
	
	long long N, M, L, d, A, B;
	
	cin >> N >> M >> L;
	
	map<long long, int> events;
	
	
	for (int i = 0; i < N; i++){
	    cin >> d;
	    A = max(d - M, (long long)(0));
	    B = min(d + M, L);
	    //cout << A << " " << B << "\n";
		events[A]++;
		events[B+1]--;
	}
	
	events[0] += 0;
	events[L+1] += 0;
	
	int ans = INT_MAX;
	int count = 0;
	
	for (auto it = events.begin(); it != events.end(); it++){
	    if (it->first>L) break;
		count += it->second;
		//cout << it->first << " " << it->second << "\n";
		ans = min(ans, count);
	}
	
	cout << ans << "\n";
	
	return 0;
}