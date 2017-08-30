#include <bits/stdc++.h>

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define iter(i,a,b) for(int i = (a) ; i < (b) ; i++)
#define mem(a,b) memset(a,b,sizeof(a))

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef vector <pii> vii;

#define INF 1000000000
#define MAXX 1005

vector< pii > adj_l[MAXX];
int dist[MAXX], V, E;
bool vis[MAXX];
vector< int > ans, AdjList[MAXX];

void init(){
	rep(i, MAXX){
		adj_l[i].clear();
		AdjList[i].clear();
		dist[i] = INF;
		vis[i] = false;
	}
	ans.clear();
}

void input(int u, int v, int w){
	adj_l[v].push_back(make_pair(w, u));
	AdjList[v].push_back(u);
}

void bellman_ford(int src){
	dist[src] = 0;
	rep(i, V - 1){
		rep(u, V){
			rep(j, (int)adj_l[u].size()){
				pii v = adj_l[u][j];
				dist[v.second] = min(dist[v.second], dist[u] + v.first);
			}
		}
	}
}

void dfs(int src){
	vis[src] = true;
	ans.push_back(src);
	rep(i, AdjList[src].size()){
		int v = AdjList[src][i];
		if(!vis[v]){
			dfs(v);
		}
	}
}

bool negCycle(){
	bellman_ford(0);
	bool hasNegCycle = false;
	rep(u, V){
		rep(j, (int)adj_l[u].size()){
			pii v = adj_l[u][j];
			if(dist[v.second] > (dist[u] + v.first)){
				hasNegCycle = true;
				dfs(v.second);
			}
		}
	}
	return hasNegCycle;
}

int main(){
	//READ("LightOJ 1108.txt");
	int tc, case_no = 0, u, v, w;
	cin>>tc;
	while(tc--){
		init();
		cin>>V>>E;
		rep(i, E){
			cin>>u>>v>>w;
			input(u, v, w);
		}
		printf("Case %d:", ++case_no);
		if(negCycle()){
			sort(ans.begin(), ans.end());
			ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
			rep(i, ans.size()){
				printf(" %d", ans[i]);
			}
			printf("\n");
		}
		else if(!negCycle()){
			printf(" impossible\n");
		}
	}
	return 0;
}
