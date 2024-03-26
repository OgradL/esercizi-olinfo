#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

void permuta(int K, char P[]) {
    
    /*
    vector<int, string> a(25);
    
    a[0] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    a[1] = "ABCDEFGHIJKLMNOPQRSTUVWXZY";
    a[2] = "ABCDEFGHIJKLMNOPQRSTUVWZXY";
    a[3] = "ABCDEFGHIJKLMNOPQRSTUVZWYX";
    a[4] = "ABCDEFGHIJKLMNOPQRSTUZVYWX";
    a[5] = "ABCDEFGHIJKLMNOPQRSTUZVYWX";
    */
    
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for (int i = 26 - K; i < 26; i+=2){
    	
    	const char *last = &s[25];
    	//s[25] = s[i];
    	//s[i] = last;
    	s.erase(26);
    	s.insert(i, last);
    	cout << s << "\n";
    	
	}
	
	//cout << s << ".\n";
	
	for (int i = 0; i < 26; i++){
		P[i] = s[i];
	}
    
    for (int i = 0; i < 25; i++){
    	cout << (int(s[i + 1]) - int(s[i])) << " ";
	}
    
//    return s;
}


int main() {
    FILE *fr, *fw;
    int K;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &K));

    char P[27];
    permuta(K, P);
    P[26] = '\0';

    fprintf(fw, "%s\n", P);
    fclose(fr);
    fclose(fw);
    return 0;
}
