#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int  V, E;
vector<int> adj_l[10005];
int par[10005], low[10005], disc[10005], _time;
bool vis[10005], AP[10005];
vector< pair<int, int> > bridge;

void input(int u, int v)
{
    adj_l[u].push_back(v);
}

void init()
{
    for(int i = 0; i < 10005; i++)
        adj_l[i].clear();
    bridge.clear();
    mem(par, -1);
    mem(low, 0);
    mem(vis, false);
    mem(AP, false);
    mem(disc, 0);
    _time = 0;
}

void dfs(int src)
{
    vis[src] = true;
    low[src] = disc[src] = (++_time);

    for(int i = 0; i < adj_l[src].size(); i++)
    {
        int v = adj_l[src][i];

        if(vis[v] == false)
        {
            par[v] = src;
            dfs(v);

            low[src] = min(low[src], low[v]);

            if(low[v] > disc[src])
            {
                AP[src] = true;
                bridge.push_back(make_pair(min(src, v), max(src, v)));
            }
        }

        else if(v != par[src])
        {
            low[src] = min(low[src], disc[v]);
        }
    }
}

bool custom_sort(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first == b.first)
        return (a.second < b.second);
    return (a.first < b.first);
}

void Bridge(){
    for(int i = 0; i < V; i++){
        if(vis[i] == false)
            dfs(i);
    }
    printf("%d critical links\n", bridge.size());
    sort(bridge.begin(), bridge.end(), custom_sort);
    for(int i = 0; i < bridge.size(); i++){
        cout<<bridge[i].first<<" - "<<bridge[i].second<<endl;
    }
    init();
}

int main()
{
    //READ("LightOJ_1026.txt");
    int t, u, v, n, case_no = 0;
    cin>>t;
    for(int k = 0; k < t; k++){
        cin>>V;
        for(int i = 0; i < V; i++){
            scanf("%d (%d)", &u, &n);
            for(int j = 0; j < n; j++){
                cin>>v;
                input(u, v);
            }
        }
        printf("Case %d:\n", ++case_no);
        Bridge();
    }
    return 0;
}
