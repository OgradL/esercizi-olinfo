#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <bits/stdc++.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int Q;
static int* ids;
static char* types;
static int* params;
static int* answers;

// Declaring functions
std::unordered_map<int, int> m;
std::vector<int> v;
void pr(){
	for (int i = 0; i < v.size(); i++){
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}
void inizia(int N, int ids[]){
	v.resize(N);
	for (int i = 0; i < N; i++){
		m[ids[i]] = i;
		v[i] = ids[i];
	}
	pr();
}
void supera(int id){
	if (m[id] == -1) return;
	int p = m[id];
	m[id]--;
	int g = v[p-1];
	v[p-1] = v[p];
	m[g]++;
	v[p] = g;
	pr();
}
void squalifica(int id){
	if (m[id] == -1) return;
	v.erase(v.begin() + m[id]);
	m[id] = -1;
	pr();
}
int partecipante(int pos){
	return v[pos-1];
	pr();
}

// Functions ad-hoc for this grader
void make_calls(int& Q, char types[], int params[], int answers[]) {
    int cnt = 0;
	for (int i = 0; i < Q; i++) {
		if (types[i] == 's') {
			supera(params[i]);
		}
		else if (types[i] == 'x') {
			squalifica(params[i]);
		}
		else if (types[i] == 'p') {
			answers[cnt++] = partecipante(params[i]);
		}
	}
    Q = cnt;
}


int main() {
	fr = stdin;
	fw = stdout;

	// Reading input
	fscanf(fr, " %d %d", &N, &Q);
	ids = (int*)malloc((N) * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, " %d", &ids[i0]);
	}
	types = (char*)malloc((Q) * sizeof(char));
	params = (int*)malloc((Q) * sizeof(int));
	for (int i0 = 0; i0 < Q; i0++) {
		fscanf(fr, " %c %d", &types[i0], &params[i0]);
	}

	// Calling functions
	inizia(N, ids);
	answers = (int*)malloc((Q) * sizeof(int));
	make_calls(Q, types, params, answers);

	// Writing output
	for (int i0 = 0; i0 < Q; i0++) {
		fprintf(fw, "%d ", answers[i0]);
	}
	fprintf(fw, "\n");

	fclose(fr);
	fclose(fw);
	return 0;
}
