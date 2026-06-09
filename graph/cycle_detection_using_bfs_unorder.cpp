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
    int v,e;
    vector<vector<int>>g;
    public:
    graph(){
        cout<<"Enter vertices and edges : ";
        cin>>v>>e;
        g.resize(v);
        cout<<"Enter edges : "<<endl;
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            g[a].pb(b);g[b].pb(a);
        }
    }
    void showAdjList(){
        for(int i=0;i<v;i++){
            cout<<i<<" : ";
            for(auto neighbour:g[i]) cout<<neighbour<<" ";cout<<endl;
        }
    }
// my implementation, had some errors, fixed with gpt.
    bool cycleDetectionBfs(int n,vector<bool> &vis){
        vector<int>parent(v,0);
        queue<int>q;
        q.push(n);
        parent[n]=-1;
        vis[n]=1;
        while(!q.empty()){
            int first = q.front();
            q.pop();
            for(auto neighbour:g[first]){
                if(!vis[neighbour]) {q.push(neighbour);parent[neighbour]=first;vis[neighbour]=1;}
                else if(neighbour!=parent[first]) return true;
            }
        }
        return false;
    }
    void hasCycle(){
        vector<bool>visited(v,false);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(cycleDetectionBfs(i,visited)){ cout<<"cycle found"<<endl; break;}
                else cout<<"no cycle"<<endl;
            }
        }
    }
};

// cout << setprecision(4) << x; //for decimal precision
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    graph g1;
    g1.hasCycle();

    return 0;
}