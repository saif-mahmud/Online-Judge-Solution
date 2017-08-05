#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define WHITE 0
#define GREY 1
#define BLACK 2
#define INF -1

vector<int> adj_l[105];
int _time, d[105], f[105], col[105];
stack <int> topo;
int V, E;

void init(){
    for(int i = 0; i < 105; i++)
        adj_l[i].clear();
    mem(d, 0);
    mem(f, 0);
    mem(col, WHITE);
    _time = 0;
}

void input(int u, int v){
    adj_l[u].push_back(v);
}

void dfs(int src){
    int u = src;
    _time = _time + 1;
    d[u] = _time;
    col[u] = GREY;
    for(int i = 0; i < adj_l[u].size(); i++){
        int v = adj_l[u][i];
        if(col[v] == WHITE)
            dfs(v);
    }
    col[u] = BLACK;
    _time = _time + 1;
    f[u] = _time;
    topo.push(u);
    return;
}

int main(){
    READ("UVa 10305.txt");
	int u, v;
	while(1){
        init();
        cin>>V>>E;
        if(V == 0 && E == 0)
            break;
        for(int i = 0; i < E; i++){
            cin>>u>>v;
            input(u, v);
        }
        for(int i = 1; i <= V; i++){
            if(col[i] == WHITE)
                dfs(i);
        }
        cout<<topo.top();
        topo.pop();
        while(!topo.empty()){
            cout<<" "<<topo.top();
            topo.pop();
        }
        cout<<endl;
	}
	return 0;
}
