#include <iostream>
#include <vector>
using namespace std;

const long long maxn = 4e5+2;

struct trie{
	bool is_word = false;
	int idx;
	trie* nodes[26] = {NULL};

	void insert(string& s, int index, int p = 0){
		if (p == s.size()){
			is_word = true;
			if (idx == 0)
				idx = index;
			else
				idx = min(idx, index);
			return;
		}
		int idx = s[p] - 'a';
		if (nodes[idx] == NULL)
			nodes[idx] = new trie();
		nodes[idx]->insert(s, index, p+1);
	}
	
	int inv(string& s, int p = 0){
		if (is_word)
			return idx;
		int idx = s[p] - 'a';
		int com = ('z' - s[p] + 1) % 26;
		int c = 26;
		for (int i = com; c--; i = (i+1)%26){
			if (nodes[i] != NULL){
				return nodes[i]->inv(s, p+1);
			}
		}
		return -1;
	}
};

int comp(string& s1, string& s2, string& str){
	int ok = 0;
	int n1 = s1.size(), n2 = s2.size();
	if (!n2)
		return 1;
	if (!n1)
		return 0;
	for (int i = 0; i < str.size(); i++){
		if (((str[i] + s1[i % n1] - 2*'a') % 26) <
			((str[i] + s2[i % n2] - 2*'a') % 26)){
				return 1;
			}
		if (((str[i] + s1[i % n1] - 2*'a') % 26) >
			((str[i] + s2[i % n2] - 2*'a') % 26)){
				return 0;
			}
	}
	return 2;
}

int main(){
	
	int N, K;
	cin >> N >> K;

	vector<trie*> words(maxn);
	vector<string> dictionary;
	string s, ans;
	for (int i = 0; i < K; i++){
		cin >> s;
		if (words[s.size()] == NULL)
			words[s.size()] = new trie();
		words[s.size()]->insert(s, i+1);
		dictionary.push_back(s);
	}

	vector<vector<int>> divisors(maxn);
	for (int i = 1; i < maxn; i++){
		for (int j = i; j < maxn; j += i){
			divisors[j].push_back(i);
		}
	}

	int n, idx_ans = 0;
	while (N--){
		cin >> s;
		n = s.size();
		ans = "";
		idx_ans = -1;

		for (int d : divisors[n]){
			if (words[d] == NULL)
				continue;
			int tmp = words[d]->inv(s);
			int ok = comp(dictionary[tmp-1], ans, s);
			if (ok == 1 || (ok == 2 && (tmp < idx_ans))){
				ans = dictionary[tmp-1];
				idx_ans = tmp;
			}
		}
		cout << idx_ans << "\n";
	}

	return 0;
}