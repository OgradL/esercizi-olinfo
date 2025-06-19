#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int chiamate = 0;
static string str;
static vector<string> sub;

void indovina(int N);

int chiedi(int K) {
  chiamate++;
  return sub[K - 1].size();
}

void rispondi(string out) {
  if (out == str) {
    cout << "Risposta corretta: " << chiamate << " chiamate eseguite" << endl;
  } else {
    cout << "Risposta sbagliata" << endl;
  }
  exit(0);
}

int main() {
  // se preferisci leggere e scrivere da file
  // ti basta decommentare le seguenti due righe:

  // ifstream cin("input.txt");
  // ofstream cout("output.txt");

  int N;
  cin >> N >> str;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j <= N; j++) {
      sub.push_back(str.substr(i, j - i));
    }
  }
  sort(sub.begin(), sub.end());

  indovina(N);

  cout << "Risposta non fornita" << endl;

  return 0;
}
