#include <stdbool.h>

bool chiedi(int X);

int indovina() {
	int ans = 0;
	for (int p = 1; p < (1<<30); p=p<<1){
		ans += chiedi(p)?p:0;
	}
	return ans;
}
