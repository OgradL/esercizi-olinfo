#include <iostream>
#include <vector>
using namespace std;

struct trie{
	trie* node[26];
	int ends = 0;
	int left = 0;
	int ans = 0;

	void add(string& s, int idx = 0){
		ends++;
		left++;
		if (s.size() == idx)
			return;
		if (node[s[idx]-'a'] == NULL)
			node[s[idx]-'a'] = new trie();
		node[s[idx]-'a']->add(s, idx+1);
	}

	void remove(string& s, int idx = 0){
		left--;
		if (s.size() == idx){
			ans = 1;
			return;
		}
		ans -= node[s[idx]-'a']->ans;
		node[s[idx]-'a']->remove(s, idx+1);
		ans += node[s[idx]-'a']->ans;
		if (left == 0 && idx != 0)
			ans = 1;
		return;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	trie* root = new trie();
	vector<string> words(N);
	for (int i = 0; i < N; i++){
		cin >> words[i];
		root->add(words[i]);
	}
	
	for (int i = 0; i < N; i++){
		root->remove(words[i]);
		cout << root->ans << "\n";
	}

	return 0;
}
