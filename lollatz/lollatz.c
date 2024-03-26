#include <stdio.h>
int main(){
    FILE *fr, *fw;
    fw = fopen("output.txt", "w");
    fr = fopen("input.txt", "r");
    int N;
    fscanf(fr, "%d", &N);
    while (N%10!=0){
        N = (N*((N%10)-1)) / 2;
    }
    fprintf(fw, "%d\n", N);
    return 0;
}