#include <stdio.h>
#include <assert.h>

long long sum(int arr[], int N){
	long long a = 0;
	for (int i = 0; i < N; i++){
		a += (long long)arr[i];
	}
	return a;
}

static const int fast_size = 100;

long long somma(FILE *f){
	int N;
	
	assert(1 == fscanf(f, "%d", &N));
	
	long long ans = 0;
	int c[fast_size];
	
	int dumb;
	
	while (N >= fast_size){
		N -= fast_size;
//		fscanf(f, "%d%d%d%d%d", &c[0], &c[0], &c[2], &c[3], &c[4]);
		dumb = fscanf(f, "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6], &c[7], &c[8], &c[9], &c[10], &c[11], &c[12], &c[13], &c[14], &c[15], &c[16], &c[17], &c[18], &c[19], &c[20], &c[21], &c[22], &c[23], &c[24], &c[25], &c[26], &c[27], &c[28], &c[29], &c[30], &c[31], &c[32], &c[33], &c[34], &c[35], &c[36], &c[37], &c[38], &c[39], &c[40], &c[41], &c[42], &c[43], &c[44], &c[45], &c[46], &c[47], &c[48], &c[49], &c[50], &c[51], &c[52], &c[53], &c[54], &c[55], &c[56], &c[57], &c[58], &c[59], &c[60], &c[61], &c[62], &c[63], &c[64], &c[65], &c[66], &c[67], &c[68], &c[69], &c[70], &c[71], &c[72], &c[73], &c[74], &c[75], &c[76], &c[77], &c[78], &c[79], &c[80], &c[81], &c[82], &c[83], &c[84], &c[85], &c[86], &c[87], &c[88], &c[89], &c[90], &c[91], &c[92], &c[93], &c[94], &c[95], &c[96], &c[97], &c[98], &c[99]);
//		printf("ro\n");
		ans += sum(c, fast_size);
	}
	
	for (int i = 0; i < N; i++){
		assert(1 == fscanf(f, "%d", &c[0]));
		ans += (long long)c[0];
	}
	
	return ans;
}
