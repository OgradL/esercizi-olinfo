#include <stdio.h>
#include <queue>

struct minStack{
	std::deque<std::pair<int, int>> q;
	int cnt_added = 0;
	int cnt_removed = 0;
	minStack(){
		q.clear();
		cnt_added = 0;
		cnt_removed = 0;
	}
	std::pair<int, int> top(){
		if (q.empty()) return {0, 0};
		return q.front();
	}
	std::pair<int, int> back(){
		if (q.empty()) return {0, 0};
		return q.back();
	}
	void push(int new_element){
		while (!q.empty() && (q.back().first > new_element))
			q.pop_back();
		q.push_back({new_element, cnt_added});
		cnt_added++;
	}
	void pop(){
		if (!q.empty() && q.front().second == cnt_removed)
			q.pop_front();
		cnt_removed++;
	}
	void pop_back(){
		if (!q.empty())
			q.pop_back();
		cnt_added--;
	}
};

const int maxn = 1000042;
long long bln[maxn][20], bld[maxn][20];
long long next[maxn];
int *times;

void inizia(int N, int T[]){
	times = T;
	next[N] = N;
	minStack ms;
	ms.push(0);
	for (int j = 0; j < 20; j++)
		bln[N][j] = N, bld[N][j] = 0;
	for (int i = N-1; i >= 0; i--){
		ms.push(T[i]);
		ms.pop_back();
		next[i] = N - ms.back().second;
		ms.push(T[i]);

		bln[i][0] = next[i];
		bld[i][0] = (next[i] - i) * T[i];
		for (int j = 1; j < 20; j++){
			bln[i][j] = bln[bln[i][j-1]][j-1];
			bld[i][j] = bld[i][j-1] + bld[bln[i][j-1]][j-1];
		}
	}
}

long long passaggio(int L, int R){
	long long ans = 0;
	for (int i = 19; i >= 0; i--){
		if (bln[L][i] <= R){
			ans += bld[L][i];
			L = bln[L][i];
		}
	}
	ans += (long long)(R - L) * (long long)times[L];
	return ans;
}