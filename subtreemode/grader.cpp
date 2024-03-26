#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct node{
	
	int index;
	int label;
	int parent;
	int numChilds;
	vector<int> beauty;
	vector<int> childs;
	
	node(){
		
	}
	
	node(int ind, int lab, int par, int nu, vector<int>& child){
		index = ind;
		label = lab;
		parent = par;
		numChilds = nu;
		childs = child;
	}
	
	void addToParent(vector<node>& nodes){
		nodes[parent].numChilds++;
		nodes[parent].childs.push_back(index);
	}
	
	vector<int> getBeauty(vector<node>& nodes){
		
		if (beauty.size() > 0){
			return beauty;
		}
		
		vector<int> arr(1, label);
		
		for (int i = 0; i < numChilds; i++){
			vector<int> arr2 = nodes[childs[i]].getBeauty(nodes);
			arr.insert(arr.end(), arr2.begin(), arr2.end());
		}
		beauty = arr;
		return beauty;
	}
	
};

vector<int> solve(int n, vector<int> p, vector<int> a){
    //oh no i wanna die
    
    vector<node> nodes(n);
    
    for (int i = 0; i < n; i++){
    	
		vector<int> ar;
    	nodes[i].index = i;
    	nodes[i].label = a[i]; 
    	nodes[i].parent = 0;
    	nodes[i].numChilds = 0;
    	nodes[i].childs = ar;
    	
	}
	
    for (int i = 1; i < n; i++){
    	nodes[i].parent = p[i];
    	nodes[i].addToParent(nodes);
	}
//    
//    for (int i = 0; i < n; i++){
//    	cout << nodes[i].index << " ";
//    	cout << nodes[i].label << " ";
//    	cout << nodes[i].parent << " ";
//    	for (int j = 0; j < nodes[i].numChilds; j++)
//    	    cout << nodes[i].childs[j] << " ";
//    	cout << endl;
//	}
    
    cout << endl << endl;
    vector<int> risultato;
    risultato.resize(n);
    
//    cout << "inizio loop per beauty\n";
    
    for (int i = 0; i < n; i++){
        vector<int> arr;
        arr = nodes[i].getBeauty(nodes);
        vector<int> arr2;
        int maxx = 0;
        int size = arr.size();
        
//        cout << size << endl;
        for (int j = 0; j < size; j++){
//        	cout << arr[j] << "arr[j]\n";
            if (arr[j] > maxx)
                maxx = arr[j];
        }
        arr2.resize(maxx + 1);
        
        for (int j = 0; j < size; j++){
            
            arr2[arr[j]]++;
            
        }
        
        int maxi = 0;
        int ind = 0;
        cout << maxx << endl;
        for (int j = 0; j < maxx + 1; j++){
            if (arr2[j] > maxi){
                maxi = arr2[j];
                ind = i;
            }
//            cout << arr2[j] << " ";
        }
        
//        cout << endl;
        
        risultato[i] = ind;
        
    }
    
    return risultato;
    
    
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//ifstream ("input0.txt", "r");
	
	int n;
	cin >> n;
	vector<int> p(n), a(n);
	for (int v = 1; v < n; v++) cin >> p[v];
    for (int v = 0; v < n; v++) cin >> a[v];
    
    //vector<int> prova(1, 3);
    //cout << prova[0] << endl;
    
    //solve(n, p, a);
    //vector<int> res(n);
    vector<int> res = solve(n, p, a);
    for (int v = 0; v < n; v++) cout << res[v] << " ";
    cout << "\n";
}
