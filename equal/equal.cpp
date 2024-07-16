#include <vector>
#include "equal.h"

using namespace std;

void make_all_equal(int N, int Q_add, int Q_compare){

	for (int b = 0; (1LL<<b) < N; b++){

		vector<int> set;
		for (int i = 0; i < N; i++){
			if ((i & (1LL<<b)) == 0){
				set.push_back(i);
			}
		}

		for (int i = 19+(b>8)+(b>11); i >= 0; i--){
			add(set, 1LL<<i);
		}

		vector<int> group;
		int base = 1 << b;

		for (int i = 0; i*base < N; i += 2){
			if (!compare(base*i, base*(i+1))){
				for (int j = base*i; j < base*(i+1); j++)
					group.push_back(j);
			}
		}

		add(group, 1);
	}
}
