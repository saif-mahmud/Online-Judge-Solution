#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

vector<int> adj_l[10005];
int par[10005], low[10005], dis[10005], _time;
bool vis[10005], AP[10005];

void input(int u, int v){
    adj_l[u].push_back(v);
    adj_l[v].push_back(u);
}

void init(){
    for(int i = 0; i < 10005; i++)
        adj_l[i].clear();
    mem(par, -1);
    mem(low, 0);
    mem(vis, false);
    mem(AP, false);
    mem(dis, 0);
    _time = 0;
}

void dfs(int src){
    vis[src] = true;
    low[src] = dis[src] = (++_time);
    int child = 0;

    for(int i = 0; i < adj_l[src].size(); i++){
        int v = adj_l[src][i];

        if(vis[v] == false){
            child++;
            par[v] = src;
            dfs(v);

            low[src] = min(low[src], low[v]);

            if((par[src] != -1) && (low[v] >= dis[src]))
                AP[src] = true;
            if((par[src] == -1) && (child > 1))
                AP[src] = true;
        }

        else if(v != par[src]){
            low[src] = min(low[src], dis[v]);
        }

    }
}

int main(){
    //READ("LightOJ 1063.txt");
    int t, u, v, V, E;
    cin>>t;
    for(int i = 1; i <=t; i++){
        init();
        cin>>V>>E;
        for(int j = 0; j < E; j++){
            cin>>u>>v;
            input(u, v);
        }
        dfs(1);
        int cnt = 0;
        for(int k = 1; k <= V; k++){
            if(AP[k])
                cnt++;
        }
        printf("Case %d: %d\n", i, cnt);
    }
	return 0;
}
