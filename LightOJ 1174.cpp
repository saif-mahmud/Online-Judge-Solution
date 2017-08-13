#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define INF -1

vector<int> adj_l[200];
int dist1[200], dist2[200], ans[200];

void init(){
    mem(dist1, INF);
    mem(dist2, INF);
    mem(ans, 0);

    for(int i = 0; i < 200; i++){
        adj_l[i].clear();
    }
}

void input(int u, int v){
    adj_l[u].push_back(v);
    adj_l[v].push_back(u);
}

void bfs_1(int src)
{
    queue<int> q;
    dist1[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj_l[u].size(); i++)
        {
            int v = adj_l[u][i];

            if(dist1[v] == INF)
            {
                dist1[v] = dist1[u] + 1;
                q.push(v);
            }
        }
    }
}

void bfs_2(int src)
{
    queue<int> q;
    dist2[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < adj_l[u].size(); i++)
        {
            int v = adj_l[u][i];

            if(dist2[v] == INF)
            {
                dist2[v] = dist2[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    int t, u, v, V, E, s, d, case_no = 0, mx = 0;
    cin>>t;
    while(t--){
        init();
        cin>>V>>E;
        for(int i = 0; i < E; i++){
            cin>>u>>v;
            input(u, v);
        }
        cin>>s>>d;
        bfs_1(s);
        bfs_2(d);
        for(int i = 0; i < V; i++){
            ans[i] = dist1[i] + dist2[i];
        }
        for(int i = 0; i < V; i++){
            if(ans[i] > mx)
                mx = ans[i];
        }
        printf("Case %d: %d\n", ++case_no, mx);
        mx = 0;
    }
    return 0;
}
