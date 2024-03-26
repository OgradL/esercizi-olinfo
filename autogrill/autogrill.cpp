#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define INF 1e18 + 10

set<long long> s;
void inizia(){
	return;
}

void apri(long long p){
	s.insert(p);
}

void chiudi(long long p){
	s.erase(p);
}

long long chiedi(long long p){
	if (s.size() == 0) return -1;
	auto ilb = s.lower_bound(p);
	long long lb = ((ilb != s.begin()) ? (*prev(ilb)) : (-1));
	long long ub = ((ilb != s.end()) ? (*ilb) : (-1));
	if (lb == -1) return ub;
	if (ub == -1) return lb;
	if (p - lb < ub - p){
		return lb;
	} else {
		return ub;
	}
}