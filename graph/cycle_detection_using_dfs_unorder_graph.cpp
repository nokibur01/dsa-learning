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
        cout<<"Enter the number of vertices : ";
        cin>>v;
        cout<<"Enter the number of edges : ";
        cin>>e;
        g.resize(v);
        cout<<"Enter the edges : "<<endl;
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
    }

    void dfsCycleDetectionHelper(int n,int p,vector<bool> &visited,vector<int> &parent,bool &flag){
        if(flag){
            return ;
        }
        parent[n]=p;
        visited[n]=1;
        for(auto val:g[n]){
            if(!visited[val]) dfsCycleDetectionHelper(val,n,visited,parent,flag);
            else if(visited[val] && parent[n]!=val){
                flag = true;
            }
        }
    }

    void dfsCycleDetection(int n,int p){
        vector<bool>visited(v,false);
        vector<int>parents(v,0);
        bool flag = false;
        dfsCycleDetectionHelper(n,p,visited,parents,flag);
        if(flag) cout<<"Cycle detected"<<endl;
        else cout<<"Cycle not detected"<<endl;
    }
};

// cout << setprecision(4) << x; //for decimal precision
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    graph g1;
    g1.dfsCycleDetection(0,-1);

    return 0;
}