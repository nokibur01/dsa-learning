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
    public:
    graph(){
        cout<<"Enter vertices:";
        cin>>v;
        g.resize(v);
        int e;
        cout<<"Enter edges:";
        cin>>e;
        cout<<"Enter edges:"<<endl;
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            g[a].pb(b);g[b].pb(a);
        }
    }

    void dfs(){
        int a;
        cout<<"Enter source node:";
        cin>>a;
        stack<int>s;
        vector<bool>visited(v,false);
        s.push(a);
        while(!s.empty()){
            int a = s.top();
            s.pop();
            visited[a]=1;
            cout<<a<<" ";
            for(auto val:g[a]){
                if(!visited[val]) s.push(val);
            }
        }
    }
};

// cout << setprecision(4) << x; //for decimal precision
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    graph g1;
    g1.dfs();

    return 0;
}