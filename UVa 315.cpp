#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

vector<int> adj_l[105];
int par[105], low[105], dis[105], _time;
bool vis[105], AP[105];

void input(int u, int v){
    adj_l[u].push_back(v);
    adj_l[v].push_back(u);
}

void init(){
    for(int i = 0; i < 105; i++)
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
int main()
{
    //READ("inp.txt");
    int u, v, V, E;
    while(true)
    {
        init();
        cin>>V;
        if(V == 0)
            break;

        getchar();
        while(true)
        {
            string inp;
            getline(cin, inp);
            stringstream ss(inp);

            ss>>u;
            if(u == 0)
                break;

            while(ss>>v)
            {
                input(u, v);
            }
        }
        dfs(1);
        int cnt = 0;
        for(int i = 1; i <= V; i++)
        {
            if(AP[i])
                cnt++;
        }
        cout<<cnt<<endl;
        cnt = 0;
    }
    return 0;
}
