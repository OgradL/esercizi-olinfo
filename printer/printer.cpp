#include <iostream>
#include <vector>
using namespace std;

vector<char> ans;

struct Trie{
	Trie* nxt[26];
	int is_word = 0;
	int longest_word = 0;

	void add(string& s, int idx = 0){
		longest_word = max(longest_word, (int)s.size());
		if (idx == s.size()){
			is_word = 1;
			return;
		}
		if (nxt[s[idx]-'a'] == NULL)
			nxt[s[idx]-'a'] = new Trie();
		nxt[s[idx]-'a']->add(s, idx+1);
	}

	void visit(){
		if (is_word){
			ans.push_back('P');
		}
		int idx_longest = -1;
		for (int i = 0; i < 26; i++){
			if (nxt[i] != NULL && nxt[i]->longest_word == longest_word)
				idx_longest = i;
		}
		for (int i = 0; i < 26; i++){
			if (nxt[i] != NULL && i != idx_longest){
				ans.push_back(char('a' + i));
				nxt[i]->visit();
			}
		}
		if (idx_longest != -1){
			ans.push_back(char('a' + idx_longest));
			nxt[idx_longest]->visit();
		}
		ans.push_back('-');
		return;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	Trie* trie = new Trie();
	string s;
	for (int i = 0; i < N; i++){
		cin >> s;
		trie->add(s);
	}

	trie->visit();

	ans.pop_back();
	while (ans.size() && ans.back() == '-')
		ans.pop_back();

	cout << ans.size() << "\n";
	for (char c : ans){
		cout << c << "\n";
	}

	return 0;
}
