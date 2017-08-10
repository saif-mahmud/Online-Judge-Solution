#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define INF -1

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c;
char grid[25][25];
int dist[25][25];

void init(){
	mem(dist, INF);
}

void bfs(int src_x, int src_y){

    dist[src_x][src_y] = 0;

    queue< pair<int, int> > q;
    q.push(make_pair(src_x, src_y));

    while(!q.empty()){

        pair<int, int> top = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int tx = top.first + dx[i];
            int ty = top.second + dy[i];

            if((tx >= 0 && tx < r) && (ty >= 0 && ty < c) && (grid[tx][ty] != '#' && grid[tx][ty] != 'm')  && dist[tx][ty] == INF){
                dist[tx][ty] = dist[top.first][top.second] + 1;
                q.push(make_pair(tx, ty));
            }
        }
    }
}

int main(){
	READ("LightOJ 1238.txt");
    int t, case_no = 0, src_x, src_y, pos_a_x, pos_a_y, pos_b_x, pos_b_y, pos_c_x, pos_c_y;
    cin>>t;
    while(t--){
		init();
        cin>>r>>c;
        getchar();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                grid[i][j] = getchar();

                if(grid[i][j] == 'h'){
                    src_x = i;
                    src_y = j;
                }

                else if(grid[i][j] == 'a'){
					pos_a_x = i;
					pos_a_y = j;
                }

                else if(grid[i][j] == 'b'){
					pos_b_x = i;
					pos_b_y = j;
                }

                else if(grid[i][j] == 'c'){
					pos_c_x = i;
					pos_c_y = j;
                }

            }
            getchar();
        }
        bfs(src_x, src_y);int ans = max(dist[pos_a_x][pos_a_y], max(dist[pos_b_x][pos_b_y], dist[pos_c_x][pos_c_y]));
        printf("Case %d: %d\n", ++case_no, ans);
    }
	return 0;
}
