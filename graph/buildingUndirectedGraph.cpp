#include <bits/stdc++.h>
#define vlli vector<long long int>
#define vi vector<int>
#define lli long long int
#define endl '\n'
#define pb push_back

using namespace std;
using st = string;

int findgcd(int n1, int n2) {
    if (n1 == 0) return n2;

    int mn = n1 > n2 ? n2 : n1;
    int mx = n1 > n2 ? n1 : n2;

    return findgcd(mx % mn, mn);
}

class Graph{
    int v;
    vector<vector<int>>g;
public:
    Graph(){
        cout<<"Enter the number of vertices : ";
        cin>>v;
        g.resize(v);
        // edges
        int edges;
        cout<<"Enter the number of edges:";
        cin>>edges;
        for(int i=0;i<edges;i++){
            int a,b;
            cout<<"Enter the two nodes that connects each edges : ";
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    void showEdges(){
        for(int i=0;i<v;i++){
            cout<<i<<" : ";
            for(auto neighbour:g[i]) cout<<neighbour<<" ";
            cout<<endl;
        }
    }
};

// cout << setprecision(4) << x; //for decimal precision
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    Graph g1;
    g1.showEdges();

    return 0;
}