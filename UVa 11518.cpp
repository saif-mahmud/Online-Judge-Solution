#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

vector<int> adj_l[10001];
bool vis[10001];

void dfs(int src){
    vis[src] = true;
    for(int i = 0; i < adj_l[src].size(); i++){
        int v = adj_l[src][i];
        if(!vis[v])
            dfs(v);
    }
}


int main(){
    //READ("UVa 11518.txt");
    int t, n, m, l, u, v, src, cnt = 0;
    cin>>t;
    while(t--){
        cin>>n>>m>>l;
        while(m--){
            cin>>u>>v;
            adj_l[u].push_back(v);
        }
        while(l--){
            cin>>src;
            dfs(src);
        }
        for(int i = 1; i <= n; i++){
            if(vis[i])
                cnt++;
        }
        cout<<cnt<<endl;
        //Reset
        mem(vis, false);
        cnt = 0;
        for(int i = 1; i <= n; i++)
            adj_l[i].clear();
    }
	return 0;
}
