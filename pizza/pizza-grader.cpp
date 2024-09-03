#include <iostream>
using namespace std;


void Bake(int K){
	cout << K << " baked!\n";
}

void Order(int N, int *A);

void Delivery(int I);

void Init();

int main(){
	
	Init();
	
	int arr[4];
	Delivery(1);
	Delivery(1);
	Delivery(1);
	Delivery(2);
	Delivery(2);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	Order(3, arr);
	Delivery(4);
	Delivery(4);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;
	Order(3, arr);
	Delivery(3);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	Order(4, arr);
	Delivery(2);
	
	
	return 0;
}
