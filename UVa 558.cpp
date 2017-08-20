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
#define MAXX 1000

vector< pii > adj_l[MAXX];
int dist[MAXX], V, E;

void init(){
	rep(i, MAXX){
		adj_l[i].clear();
		dist[i] = INF;
	}
}

void input(int u, int v, int w){
	adj_l[u].push_back(make_pair(w, v));
	//adj_l[v].push_back(make_pair(w, u));
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

bool negCycle(){
	bool hasNegCycle = false;
	rep(u, V){
		rep(j, (int)adj_l[u].size()){
			pii v = adj_l[u][j];
			if(dist[v.second] > (dist[u] + v.first))
				hasNegCycle = true;
		}
	}
	return hasNegCycle;
}

int main(){
	//READ("UVa 558.txt");
	int tc, case_no = 0, u, v, w;
	cin>>tc;
	while(tc--){
		init();
		cin>>V>>E;
		rep(i, E){
			cin>>u>>v>>w;
			input(u, v, w);
		}
		bellman_ford(0);
		if(negCycle())
			printf("possible\n");
		else if(!negCycle())
			printf("not possible\n");
	}
	return 0;
}

