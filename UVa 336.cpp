#include <bits/stdc++.h>

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define INF -1

vector<int> adj_l[35];
int dist[35];

int bfs(int src, int x)
{
    int cnt = 1;
    memset(dist, INF, sizeof(dist));
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj_l[u].size(); i++)
        {
            int v = adj_l[u][i];
            if(dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                if(dist[v] <= x)
                    cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    //READ("UVa 336.txt");
    //WRITE("UVa 336_out.txt");
    int u, v, a, b, E, src,cnt = 0, x, case_no = 0;
    map<int, int> node_map;
    while(scanf("%d", &E) == 1 && E != 0)
    {
        node_map.clear();
        int cnt = 0, node_no = 0;
        for(int i = 0; i < 35; i++)
            adj_l[i].clear();
        for(int i = 0; i < E; i++)
        {
            scanf("%d %d", &a, &b);

            if(!node_map[a])
            {
                node_map[a]=++node_no;
                cnt++;
            }
            if(!node_map[b])
            {
                node_map[b] = ++node_no;
                cnt++;
            }
            u = node_map[a];
            v = node_map[b];
            adj_l[u].push_back(v);
            adj_l[v].push_back(u);
        }
        while(true)
        {
            scanf("%d %d", &src, &x);
            if(!src && !x)
                break;
            int ans;
            if(!node_map[src])
                ans = cnt;
            else ans = cnt - bfs(node_map[src],x);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++case_no, ans, src, x);
        }
    }
    return 0;
}
