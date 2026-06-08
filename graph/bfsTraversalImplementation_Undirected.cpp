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
        cout<<"Enter number of vertices:";
        cin>>v;
        g.resize(v);
        int edg;
        cout<<"Enter number of edges : ";
        cin>>edg;
        cout<<"Enter the edges : ";
        for(int i=0;i<edg;i++){
            int a,b;
            cin>>a>>b;
            g[a].pb(b);g[b].pb(a);
        }
    }
    void showGraph(){
        for(int i=0;i<v;i++){
            cout<<i<<":";
            for(auto neighbour:g[i]) cout<<neighbour<<" ";cout<<endl;
        }
    }

    void BFS(){
        int a;
        cout<<"Enter starting node : ";
        cin>>a;
        queue<int>q;
        q.push(a);
        vector<bool>visited(v,false);
        vector<int>ans;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            if(!visited[a]){
                visited[a]=true;
                ans.pb(a);
                for(auto val:g[a]) q.push(val);
            }
        }
        for(auto val:ans) cout<<val<<" ";
    }
};

// cout << setprecision(4) << x; //for decimal precision
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    graph g1;
    g1.BFS();

    return 0;
}