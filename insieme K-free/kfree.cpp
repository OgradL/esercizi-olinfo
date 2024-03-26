#include <bits/stdc++.h>

using namespace std;

//bool binarySearch(int* arr, int l, int r, int x)
//{
//    if (r >= l) {
//        int mid = l + (r - l) / 2;
// 
//        if (arr[mid] == x)
//            return true;
// 
//        if (arr[mid] > x)
//            return binarySearch(arr, l, mid - 1, x);
// 
//        return binarySearch(arr, mid + 1, r, x);
//    }
//    
//    return false;
//}



int Trova(int N, int K, int* insieme) {
	
	unordered_map<int, int> is_there;
	
	for (int i = 0; i < N; i++){
		is_there[insieme[i]] = 1;
	}
	
    sort(insieme, insieme + N);
    
    //int ma = insieme.back();
    
    unordered_map<int, int> data;
    
    int count = N;
    
    for (int i = 0; i < N; i++){
        
//		cout << i << " " << count << "\n";
        
        if (is_there[insieme[i] * K] == 1){
            
        	if (data[insieme[i]] > 0){
        		continue;
			}
            
			data[insieme[i] * K]++;
			count--;
		}
		
//		cout << count << "\n";
        
    }
    
    
    return count;
}

int main(){
	
	int N, K;
	
	cin >> N >> K;
	
	int ins[100000];
	
	for (int i = 0; i < N; i++){
		cin >> ins[i];
	}
	
	cout << Trova(N, K, ins) << "\n";
	
}
