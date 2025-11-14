#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string S;
	cin >> S;

	int cnt = 0, speed = 0, ans = 0;
	
	for (char c : S){
		if (c == 'H') cnt++;
		else if(c == 'U') speed -= 11;
		else if(c == 'D') speed += 9;
		else if(c == 'B') speed += 10;
		
		while (speed < 1){
			cnt--;
			speed += 10;
			ans++;
		}

		if (cnt < 0){
			ans = -1;
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}
