#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Bake(int K);

int order_num;
int quantity[8];
queue<int> ordini[1<<8];

void Init(){
	order_num = 0;
}

void Order(int N, int *A){
	short ingr = 0;
	bool ok = true;
	for (int i = 0; i < N; i++){
		ok &= quantity[A[i]] > 0;
		ingr |= 1 << A[i];
	}
	if (ok){
		Bake(order_num);
		for (int i = 0; i < N; i++)
			quantity[A[i]]--;
	} else {
		ordini[ingr].push(order_num);
	}
	order_num++;
}

void Delivery(int I){
	quantity[I]++;

	if (quantity[I] > 1)
		return;

	int t_ready = 1e9;
	short mask_ready;
	for (short mask = 0; mask < (1<<8); mask++){
		if (!(mask & (1<<I)) || ordini[mask].empty())
			continue;
		
		bool ok = true;
		for (int i = 0; i < 8; i++)
			if (mask & (1<<i))
				ok &= quantity[i] > 0;


		if (ok && t_ready > ordini[mask].front()){
			mask_ready = mask;
			t_ready = ordini[mask].front();
		}
	}

	if (t_ready == 1e9)
		return;

	Bake(t_ready);
	ordini[mask_ready].pop();
	for (int i = 0; i < 8; i++)
		if (mask_ready & (1<<i))
			quantity[i]--;
}

