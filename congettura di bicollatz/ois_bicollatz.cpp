#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

int bicollatz(int A, int B) {
    
    if (A != 1 || B != 1){
	    if (A % 2 == 0 && B % 2 == 0){
	        return bicollatz(A/2, B/2);
	    } else if (A % 2 == 1 && B % 2 == 1){
	        return bicollatz(A*3+1, B*3+1);
	    } else {
	        if (A % 2 == 1){
	            return bicollatz(A+3, B);
	        } else {
	            return bicollatz(A, B+1);
	        }
		}
	} else {
		return 0;
	}
	
    //cout << A << " " << B << "\n";
    
    
    
}



int main() {
    FILE *fr, *fw;
    int A, B;
    
    
    //fr = fopen("input.txt", "r");
    //fw = fopen("output.txt", "w");
    //assert(2 == fscanf(fr, "%d %d", &A, &B));
    //fprintf(fw, "%d\n", bicollatz(A, B));
    //fclose(fr);
    //fclose(fw);
    
    cin >> A >> B;
    cout << bicollatz(A, B);
    return 0;
}
