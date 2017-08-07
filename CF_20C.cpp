#include <bits/stdc++.h>

#define INF 1e17

using namespace std;

int V, E, par[100005];

vector<int> adj_l[100005];
vector<int> cost[100005];
long long dist[100005];

void init(){
    memset(par, -1, sizeof(par));

    for(int i = 1; i <= V; i++)
        dist[i] = INF;

}

void input(int u, int v, int w)
{
    adj_l[u].push_back(v);
    adj_l[v].push_back(u);

    cost[u].push_back(w);
    cost[v].push_back(w);
}


void dijkstra(int src)
{
    dist[src] = 0;

    priority_queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int u = q.top();
        q.pop();

        for(int i = 0; i < adj_l[u].size(); i++)
        {
            int v = adj_l[u][i];
            if(dist[u] + cost[u][i] < dist[v]){
                dist[v] = dist[u] + cost[u][i];
                par[v] = u;
                q.push(v);
            }
        }
    }
}
void path(int v){
    if(par[v] == -1)
        return;

    path(par[v]);
    cout<<" "<<v;
}

void shortestPath(int u, int v){
    dijkstra(u);
    if(par[v] != -1){
        cout<<u;
        path(v);
    }
    else
        cout<<"-1";
}


int main()
{
    //freopen("Dijkstra.txt", "r", stdin);
    int u, v, w;
    cin>>V>>E;
    init();
    for(int i = 0; i < E; i++){
        cin>>u>>v>>w;
        input(u, v, w);
    }
    shortestPath(1, V);
    cout<<endl;
    return 0;
}

