#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

template <typename T>
ostream& operator<<(ostream& o, const vector<T>& v){
    o << "[ ";
    for(auto i: v){
        o << i << " ";
    }
    o << "]";
    return o;
};

string toStr(vector<int> V, int except = -1){
  string s;
  char c;
  for(int i: V){
    c = i + '0';
    if(c == -1 + '0'){
      continue;
    }
    s += c;
  }
  return s;
}

string solve(string input){
  vector<int> V;
  set<char> moduli;
  for(char c: input){
    c -= '0';
    moduli.insert(c % 3);
    V.pb(c);
  }
  int modulo_sum = 0;
  for(int i: V){
    modulo_sum += i % 3;
  }
  
  modulo_sum %= 3;
  if(modulo_sum == 0){
    return toStr(V);
  }else{
    // prova a rimuovere una sola cifra
    int rmd = modulo_sum;
    if(moduli.count(rmd)){
      ll last = -1;
      for(int i = 0; i<V.size(); i++){
        if((V[i] % 3) == rmd){
          if(V[i] < V[i+1]){
            V[i] = -1;
            return toStr(V);
          }
          last = i;
        }
      }
      V[last] = -1;
      return toStr(V);
    }else{
      rmd = 3 - rmd;
      if(moduli.count(rmd) >= 2){
        vector<int> rec;
        short lts = 2;

        for(int i = 0; i<V.size(); i++){
          if ((V[i]) % 3 == rmd){
            if(V[i] < V[i+1]){
              V[i] = -1;
              lts--;
              if(lts == 0){return toStr(V);}
              rec.pb(i);
            }
          }
        }
        while(lts > 0){
          V[V.size()-lts] = -1;
          lts--;
        }
        return toStr(V);
      }
      else{
        return "-1";
      }
    }
  }
}

int main(){
  int N;
  cin >> N;
  string input;
  for(int _ = 0; _ < N; _++){
    cin >> input;
    cout << stoi(solve(input)) << endl;
  }
}
