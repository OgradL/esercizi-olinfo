#include <iostream>

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int n;
	std::cin >> n;

	if (n == 1){
		std::cout << "-1\n";
	} else if (n == 2){
		std::cout << "15\n";
	} else {
		for (int i = 0; i < n-4; i += 2)
			std::cout << "15";
		if (n&1)
			std::cout << "111\n";
		else
			std::cout << "1515\n";
	}


	return 0;
}