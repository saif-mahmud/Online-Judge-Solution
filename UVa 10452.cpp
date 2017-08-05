#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

char path[] = {'I', 'E', 'H', 'O', 'V', 'A', '#'};
int r, c;
int dx[] = {0, -1, 0};
int dy[] = {1, 0, -1};
string moves[] = {"right", "forth", "left"}, grid[10];

void dfs(int src_x, int src_y, int x){
    if(grid[src_x][src_y] == '#'){
        cout<<endl;
        return;
    }

    for(int i = 0; i < 3; i++){
        if((src_x + dx[i] >= 0) && (src_y + dy[i] >= 0 && src_y + dy[i] < c)){
            if(grid[src_x + dx[i]][src_y + dy[i]] == path[x]){
                cout<<moves[i];
                if(x < 6)
                    cout<<" ";
                dfs(src_x + dx[i], src_y + dy[i], ++x);
            }
        }
    }
}

int main(){
    READ("UVa 10452.txt");
    int t, src_x, src_y;
    cin>>t;
    while(t--){
        cin>>r>>c;
        for(int i = 0; i < r; i++){
                cin>>grid[i];
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '@'){
                    src_x = i;
                    src_y = j;
                }
            }
        }
        dfs(src_x, src_y, 0);
    }
	return 0;
}
