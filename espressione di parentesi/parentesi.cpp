#include <bits/stdc++.h>

using namespace std;

int conv(char a){
	if (a == '(') return 1;
	if (a == '[') return 2;
	if (a == '{') return 3;
	if (a == '<') return 4;
	
	if (a == ')') return -1;
	if (a == ']') return -2;
	if (a == '}') return -3;
	if (a == '>') return -4;
}

int main(){
	
	int N;
	
	cin >> N;
	
	stack<int> s;
	
	string st;
	cin >> st;
	
	for (int i = 0; i < N; i++){
		
		int t = conv(st[i]);
		
		if (!s.empty()){
			if (abs(t) == s.top()){
				s.pop();
			} else {
				
			}
		}
		
	}
	
	return 0;
}
