#include <bits/stdc++.h>

using namespace std;


int* append(int value, int A[], int len){
  int newA[len];
  for (int i = 0; i < len - 1; i++){
    newA[i] = A[i];
  }
  newA[len - 1] = value;
  return newA;
}


int main(){
	
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	
	//int A;
	
	//cin >> A;
	
	
	vector<int> A;
	int len = 11;
	
	//A = append(11, A, len++);
	
	for (int i = 0; i < len; i++){
		cout << A[i] << " ";
	}
	cout << "\n";
	
}
