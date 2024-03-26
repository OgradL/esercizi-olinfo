/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// constraints

// input data
int H0, M0, H1, M1;

int main() {

	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    assert(4 == scanf("%d%d%d%d", &H0, &M0, &H1, &M1));
	
	int sleepH = 0;
	int sleepM = 0;
	
	int tempo0 = M0 + H0 * 60;
	int tempo1 = M1 + H1 * 60;
	
	if (tempo0 > tempo1){
		sleepH = (60 * 24 - tempo0 + tempo1) / 60;
		sleepM = (60 * 24 - tempo0 + tempo1) % 60;
	} else {
		sleepH = (tempo1 - tempo0) / 60;
		sleepM = (tempo1 - tempo0) % 60;
	}
	
	
	
	/*int timeH = 0;
    if (H0 > H1){
    	timeH = (H1 + 24 - H0);
    	//cout << time << "\n";
    	//cout << "bob\n";
	} else {
		timeH = H1 - H0;
	}
    
    int timeM = 0;
    if (M0 > M1){
    	timeM = (M1 + 60 - M0);
    	timeH--;
    	//cout << "bob\n";
	} else {
		timeM = M1 - M0;
	}
	
	if (H0 == 0 && H1 == 0 && M0 > M1){
		timeH = 23;
	}*/
	
	
	//sleepH = timeH;
	//sleepM = timeM;
	
    printf("%d%s%d\n", sleepH, " ", sleepM);
    return 0;
}
