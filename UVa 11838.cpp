#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

vector<int> adj_l[2005];
int par[2005], low[2005], dis[2005], _time, V, E;
bool vis[2005], AP[2005];

void input(int u, int v){
    adj_l[u].push_back(v);
}

void input_2(int u, int v){
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
    par[src] = -1;
    low[src] = dis[src] == ++_time;
    int child = 0;

    for(int i = 0; i < adj_l[src].size(); i++){
        int v = adj_l[src][i];

        if(!vis[v]){
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
    READ("UVa 11838.txt");
    int u, v, p;
    while(1){
        init();
        cin>>V>>E;
        if(V == 0 && E == 0)
            break;
        for(int i = 0; i < E; i++){
            cin>>u>>v>>p;
            if(p == 1)
                input(u, v);
            else if(p == 2)
                input_2(u, v);
        }
        dfs(1);
        int cnt = 0;
        for(int i = 1; i <= V; i++){
            if(AP[i])
                cnt++;
        }
        cout<<cnt<<endl;
    }
	return 0;
}


