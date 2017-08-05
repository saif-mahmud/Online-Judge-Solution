#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define INF -1

struct quad{
    int w, x, y, z;
    quad(int _w, int _x, int _y, int _z){
        w = _w;
        x = _x;
        y = _y;
        z = _z;
    }
};

int dw[] = {1, -1, 0, 0, 0, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 0, 0, 1, -1};

int wheel[10][10][10][10], dist[10][10][10][10];

void bfs(int src_w, int src_x, int src_y, int src_z){
    mem(dist, INF);
    dist[src_w][src_x][src_y][src_z] = 0;
    queue< quad > q;
    q.push(quad(src_w, src_x, src_y, src_z));
    while(!q.empty()){
        quad top = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            int tw = top.w + dw[i];
            int tx = top.x + dx[i];
            int ty = top.y + dy[i];
            int tz = top.z + dz[i];
            if(tw == 10) tw = 0;
            if(tx == 10) tx = 0;
            if(ty == 10) ty = 0;
            if(tz == 10) tz = 0;
            if(tw == -1) tw = 9;
            if(tx == -1) tx = 9;
            if(ty == -1) ty = 9;
            if(tz == -1) tz = 9;
            if(wheel[tw][tx][ty][tz] != -1 && dist[tw][tx][ty][tz] == INF){
                dist[tw][tx][ty][tz] = dist[top.w][top.x][top.y][top.z] + 1;
                q.push(quad(tw, tx, ty, tz));
            }
        }
    }
}

int main(){
    READ("UVa 10067.txt");
    int t, src_w, src_x, src_y, src_z, dest_w, dest_x, dest_y, dest_z, n, w, x, y, z;
    cin>>t;
    while(t--){
        cin>>src_w>>src_x>>src_y>>src_z;
        cin>>dest_w>>dest_x>>dest_y>>dest_z;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>w>>x>>y>>z;
            wheel[w][x][y][z] = -1;
        }
        bfs(src_w, src_x, src_y,src_z);
        cout<<dist[dest_w][dest_x][dest_y][dest_z]<<endl;

        mem(wheel, 0);
    }
    return 0;
}
