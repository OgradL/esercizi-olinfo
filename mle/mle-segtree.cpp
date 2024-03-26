#include <iostream>
#include <vector>
using namespace std;

struct Node{
    long long v;
    long long lazyset = 0;
    Node(){
        v = 0;
    }
    Node(int _v){
        v = _v;
    }
    void merge(const Node& a, const Node& b){
        lazyset = 0;
        v = 0;
    }
};

struct ST{
    
    int n, real_size = 1;
    vector<Node> nodes;
    
    ST(int N){
        
        n = N;
        
        while (real_size < n)
            real_size *= 2;
        
        nodes.assign(2 * real_size, Node());
        
    }
    
    void fixlazy(int u, int l, int r){
        
        int laz = nodes[u].lazyset;
        if (laz != -1)
            nodes[u].v = laz;
        nodes[u].lazyset = -1;
        if (u < real_size && laz != -1){
            nodes[u * 2].lazyset = laz;
            nodes[u*2+1].lazyset = laz;
        }
    }
    
    
    void set(int u, int l, int r, int x, int y, int c){
        fixlazy(u, l, r);
        if (l >= y || r <= x){
            return;
        }
        
        if (x <= l && r <= y){
            nodes[u].lazyset = c;
            fixlazy(u, l, r);
            return;
        }
        
        set(u * 2, l, (l+r)/2, x, y, c);
        set(u*2+1, (l+r)/2, r, x, y, c);
    }
    
    void set(int x, int y, int c){
        set(1, 0, real_size, x, y, c);
    }
    
    
    vector<int> res(int u, int l, int r){
        fixlazy(u, l, r);
        vector<int> empt;
        if (r - l == 1)
            if (u < real_size + n)
                return vector<int>(1, nodes[u].v);
            else 
                return empt;
        
        //cerr << u << " " << l << " " << r << "\n";
        //cerr << "t1\n";
        vector<int> tmp, t1, t2;
        t1 = res(u * 2, l, (l+r)/2);
        //cerr << "t2\n";
        t2 = res(u*2+1, l, (l+r)/2);
        //cerr << "t3\n";
        //cerr << tmp.size() << " " << t1.size() << "\n";
        if (t1.size() > 0)
            tmp.insert(tmp.end(), t1.begin(), t1.end());
        //cerr << "t4\n";
        if (t2.size() > 0)
        tmp.insert(tmp.end(), t2.begin(), t2.end());
        //cerr << "t5\n";
        
        return tmp;
    }
    
    vector<int> res(){
        return res(1, 0, real_size);
    }
    
    
    void print(){
        int l = 1;
        int c = 0;
        for (int i = 1; i < 2*real_size; i++){
            cout << nodes[i].v << " " << nodes[i].lazyset << " | ";
            c++;
            if (c == l){
                c = 0;
                l *= 2;
                cout << "\n";
            }
        }
    }
};


void Colora(int N, int Q, vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& murale) {
    ST segtree(N);
    
    for (int i = 0; i < Q; i++){
        segtree.set(A[i], B[i]+1, C[i]);
        //segtree.print();
        //cout << "\n\n\n";
    }
    //cerr << "rc che hc ec\n";
    vector<int> res = segtree.res();
    //segtree.print();
    //cerr << "fh";
    for (int i = 0; i < N; i++)
        murale[i] = res[i];
}