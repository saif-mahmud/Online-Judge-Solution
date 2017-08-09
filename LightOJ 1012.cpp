#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define INF -1

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c, cnt;
char grid[25][25];
bool vis[25][25];

void dfs(int src_x, int src_y){
    for(int i = 0; i < 4; i++){

        int tx = src_x + dx[i];
        int ty = src_y + dy[i];

        if((tx >= 0 && tx < r) && (ty >= 0 && ty < c) && grid[tx][ty] == '.' && vis[tx][ty] == false){
            vis[tx][ty] = true;
            cnt++;
            dfs(tx, ty);
        }
    }
}

int main(){
    READ("LightOJ 1012.txt");
    int t, case_no = 0, src_x, src_y;
    cin>>t;
    while(t--){
        mem(vis, false);
        cin>>c>>r;
        getchar();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                grid[i][j] = getchar();

                if(grid[i][j] == '@'){
                    src_x = i;
                    src_y = j;
                    vis[src_x][src_y] = true;
                }
            }
            getchar();
        }
        cnt = 1;
        dfs(src_x, src_y);
        printf("Case %d: %d\n", ++case_no, cnt);
    }
	return 0;
}
