#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define INF -1

vector<int> adj_l[25];
int dist[25];

int bfs(int src, int dest)
{
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
                if(v == dest)
                    return dist[v];
                q.push(v);
            }
        }
    }
}


int main(){
    //READ("UVa 567.txt");
    int u, v, x, t, src, dest, case_no = 0;
    while(1){
        for(int i = 1; i <= 19; i++){
            if(scanf("%d", &x) == EOF)
                return 0;
            for(int j = 0; j < x; j++){
                scanf("%d", &v);
                adj_l[i].push_back(v);
                adj_l[v].push_back(i);
            }
        }
        scanf("%d", &t);
        printf("Test Set #%d\n", ++case_no);
        for(int i = 0; i < t; i++){
            scanf("%d %d", &src, &dest);
            printf("%2d to %2d: %1d\n", src, dest, bfs(src, dest));
        }
        printf("\n");
        for(int i = 0; i < 25; i++)
            adj_l[i].clear();
    }
	return 0;
}
