#include <bits/stdc++.h>

using namespace std;


#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

struct cell{
	
	char slash;
	vector<bool> dirs;		
//	map<string, bool> dirs;
	
};

void fix_cell(cell& cella){
	if (cella.slash == '/'){
		cella.dirs[LEFT] = cella.dirs[UP] = cella.dirs[UP] || cella.dirs[LEFT];
		cella.dirs[RIGHT] = cella.dirs[DOWN] = cella.dirs[DOWN] || cella.dirs[RIGHT];
	} else {
		cella.dirs[UP] = cella.dirs[RIGHT] = cella.dirs[UP] || cella.dirs[RIGHT];
		cella.dirs[LEFT] = cella.dirs[DOWN] = cella.dirs[LEFT] || cella.dirs[DOWN];
	}
}

void visit(int i, int j, int pos, vector<vector<cell> >& S, int N, int M){
	
	if (i < 0 || j < 0 || i >= N || j >= M){
		return ;
	}
	
	if (S[i][j].dirs[pos] == true){
		return ;
	}
	S[i][j].dirs[pos] = true;
	
	fix_cell(S[i][j]);
	
	
	
	if (S[i][j].slash == '/'){
		if (pos == UP){
			visit(i, j - 1, RIGHT, S, N, M);
			visit(i - 1, j, DOWN, S, N, M);
			
		} else if (pos == DOWN){
			visit(i, j + 1, LEFT, S, N, M);
			visit(i + 1, j, UP, S, N, M);
			
		} else if (pos == RIGHT){
			visit(i + 1, j, UP, S, N, M);
			visit(i, j + 1, LEFT, S, N, M);
			
		} else if (pos == LEFT){
			visit(i - 1, j, DOWN, S, N, M);
			visit(i, j - 1, RIGHT, S, N, M);
			
		}
	} else {
		if (pos == UP){
			visit(i, j + 1, LEFT, S, N, M);
			visit(i - 1, j, DOWN, S, N, M);
			
		} else if (pos == DOWN){
			visit(i, j - 1, RIGHT, S, N, M);
			visit(i + 1, j, UP, S, N, M);
			
		} else if (pos == RIGHT){
			visit(i - 1, j, DOWN, S, N, M);
			visit(i, j + 1, LEFT, S, N, M);
			
		} else if (pos == LEFT){
			visit(i + 1, j, UP, S, N, M);
			visit(i, j - 1, RIGHT, S, N, M);
			
		}
	}
	
	
}

void print_map(vector<vector<cell> >& S){
	for (int i = 0; i < S.size(); i++){
    	for (int j = 0; j < S[i].size(); j++){
    		cout << S[i][j].slash << " " << S[i][j].dirs[UP] << " " << S[i][j].dirs[DOWN] << " " << S[i][j].dirs[LEFT] << " " << S[i][j].dirs[RIGHT] << ", ";
		}
		cout << "\n";
	}
	cout << "\n";
}


int main() {
	
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	
	int N, M;
	
    cin >> N >> M;
    
    vector<vector<cell> > S(N, vector<cell>(M));
    
    string line;
    
    for (int i = 0; i < N; i++){
        cin >> line;
        for (int j = 0; j < M; j++){
        	S[i][j].dirs.resize(4);
        	S[i][j].slash = line[j];
		}
	}
    
    int colors = 0;
    
    for (int i = 0; i < N; i++){
    	for (int j = 0; j < M; j++){
    		if (!S[i][j].dirs[UP]){
    			colors++;
    			visit(i, j, UP, S, N, M);
//    			print_map(S);
			}
			if (!S[i][j].dirs[DOWN]){
				colors++;
				visit(i, j, DOWN, S, N, M);
//				print_map(S);
			}
		}
	}
    
    
    cout << colors << endl; // print the result
    return 0;
}
