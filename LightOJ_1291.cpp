#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int  V, E;
vector<int> adj_l[10005];
set<int> adj_l2[10005];
int par[10005], low[10005], disc[10005], _time, cc[10005], nbridge[10005];
bool vis[10005], AP[10005];
vector< pair<int, int> > bridge;

void init()
{
    for(int i = 0; i < 10005; i++){
        adj_l[i].clear();
        adj_l2[i].clear();
    }
    bridge.clear();
    mem(par, -1);
    mem(low, 0);
    mem(vis, false);
    mem(AP, false);
    mem(disc, 0);
    _time = 0;
    mem(cc, 0);
    mem(nbridge, 0);
}

void input(int u, int v)
{
    adj_l[u].push_back(v);
    adj_l[v].push_back(u);
    adj_l2[u].insert(v);
    adj_l2[v].insert(u);
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
                adj_l2[src].erase(v);
                adj_l2[v].erase(src);
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
    sort(bridge.begin(), bridge.end(), custom_sort);
}

void CC(){
    int current_cc = 0;
    mem(vis, false);

    for(int i = 0; i < V; i++){
        if(vis[i])
            continue;

        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(vis[u])
                continue;

            vis[u] = true;
            cc[u] = current_cc;

            set<int>::iterator j;
            for(j = adj_l2[u].begin(); j != adj_l2[u].end(); j++){
                q.push(*j);
            }
        }
        current_cc++;
    }
    for(int k = 0; k < bridge.size(); k++){
        nbridge[cc[bridge[k].first]]++;
        nbridge[cc[bridge[k].second]]++;
    }
    int ans = 0;
    for(int i = 0; i < current_cc; i++){
            if(nbridge[i] == 1)
                ans++;
    }
    ans = (ans + 1) / 2;
    printf("%d\n", ans);
}

int main()
{
    //READ("LightOJ_1291.txt");
    int t, u, v, n, case_no = 0;
    cin>>t;
    for(int k = 0; k < t; k++){
        init();
        cin>>V>>E;
        for(int i = 0; i < E; i++){
            cin>>u>>v;
            input(u, v);
        }
        printf("Case %d: ", ++case_no);
        Bridge();
        CC();
    }
    return 0;
}
