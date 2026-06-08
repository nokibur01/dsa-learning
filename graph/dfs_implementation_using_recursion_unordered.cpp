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

class graph{
    int v;
    vector<vector<int>>g;
    vector<bool> visited;
    public:
    graph(){
        cout<<"Enter number of vertices : ";
        cin>>v;
        g.resize(v);
        visited.resize(v,false);
        int e;
        cout<<"Enter number of edges : ";
        cin>>e;
        cout<<"Enter edges : ";
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            g[a].pb(b);g[b].pb(a);
        }
    }

    void dfs(int st){
        cout<<st<<" ";
        visited[st]=1;
        for(auto val:g[st]){
            if(!visited[val]){
                dfs(val);
            }
        }
    }
};

// cout << setprecision(4) << x; //for decimal precision
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    graph g1;
    cout<<"Enter starting vertices : ";
    int st;
    cin>>st;
    g1.dfs(st);

    return 0;
}