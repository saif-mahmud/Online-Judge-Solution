#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define INF -1

vector<int> adj_l[2501];
int dist[2501], cnt[2501];

void input(int u, int v){
    adj_l[u].push_back(v);
    //adj_l[v].push_back(u);
}

void bfs(int src)
{
    mem(dist, INF);
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
                cnt[dist[v]]++;
            }
        }
    }
}


int main(){
    //READ("UVa 924.txt");
    int t, v, n, x, src;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        for(int j = 0; j < x; j++){
            scanf("%d", &v);
            input(i, v);
        }
    }
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int  mx = 0, mx_idx = 0;
        scanf("%d", &src);
        bfs(src);
        for(int j = 1; j < n; j++){
            if(cnt[j] > mx){
                mx = cnt[j];
                mx_idx = j;
            }
        }
        if(mx)
            printf("%d %d\n", mx, mx_idx);
        else
            printf("0\n");
        mem(dist, INF);
        mem(cnt, 0);
    }
	return 0;
}
