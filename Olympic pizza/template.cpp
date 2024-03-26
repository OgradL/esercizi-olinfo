
//#include "pizza.h"

#include <bits/stdc++.h>

using namespace std;

void Bake(int K){
	cout << K << " baked!\n";
}

struct order{
	
	int order_num;
	int N;
	int A[3];
	
	order(){
		
	}
	
	order(int c, int b, int* arr){
		
		order_num = c;
		N = b;
		A = *arr;
		
	}
	
	void bak(vector<int>& ingred){
		Bake(order_num);
		
		for (int i = 0; i < ingred.size(); i++){
			ingred[i]--;
		}
	}
	
};

int order_num;

vector<int> ingred(8, 0);

vector<order> orders;

void Init() {

  order_num = 0;

}

void Order(int N, int *A) {

  orders.push_back(order(order_num, N, A));
//  Bake(order_num);
  order_num++;
}

void Delivery(int I) {
	ingred[I]++;
	
	for (int i = 0; i < orders.size(); i++) {
		
		bool good = true;
		
		for (int s = 0; s < orders[i].N; s++){
			if (ingred[orders[i].A[s]] > 0){
				good = good && true;
			} else {
				good = good && false;
			}
		}
		
		if (good){
			orders[i].bak(ingred);
			orders.pop_back();
		}
		
	}
	
}

int main(){
	
	Init();
	
	Delivery(1);
	Delivery(1);
	Delivery(1);
	Delivery(2);
	Delivery(2);
	Order(3, {1, 2, 3});
	Delivery(4);
	Delivery(4);
	Order(3, {1, 2, 4});
	Delivery(3);
	Order(4, {1, 2, 3, 4});
	Delivery(2);
	
	
	return 0;
}

