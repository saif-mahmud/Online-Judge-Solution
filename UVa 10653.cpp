#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define INF -1

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c;
int grid[1005][1005], dist[1005][1005];

void bfs(int src_x, int src_y){
    mem(dist, INF);
    dist[src_x][src_y] = 0;
    queue< pair<int, int> > q;
    q.push(pair <int, int>(src_x, src_y));
    while(!q.empty()){
        pair<int, int> top = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int tx = top.first + dx[i];
            int ty = top.second + dy[i];
            if((tx >= 0 && tx < r) && (ty >= 0 && ty < c) && grid[tx][ty] != -1 && dist[tx][ty] == INF){
                dist[tx][ty] = dist[top.first][top.second] + 1;
                q.push(pair <int, int>(tx, ty));
            }
        }
    }
}

int main(){
    //READ("UVa 10653.txt");
    int n, x, mine_r, mine_c, src_x, src_y, dest_x, dest_y;
    while(1){
        scanf("%d %d", &r, &c);
        if(r == 0 && c == 0)
            break;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &mine_r, &x);
            for(int j = 0; j < x; j++){
                scanf("%d", &mine_c);
                grid[mine_r][mine_c] = -1;
            }
        }
        scanf("%d %d", &src_x, &src_y);
        bfs(src_x, src_y);
        scanf("%d %d", &dest_x, &dest_y);
        printf("%d\n", dist[dest_x][dest_y]);
        mem(grid, 0);
    }
    return 0;
}
