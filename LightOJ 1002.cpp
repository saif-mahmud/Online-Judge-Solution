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
#define MAXX 505

vii adj_l[MAXX];
int dist[MAXX];
int V, E;

void init(){
	for(int i = 0; i < MAXX; i++){
		adj_l[i].clear();
		dist[i] = INF;
	}
}

void input(int u, int v, int w){
	adj_l[u].push_back(make_pair(w, v));
	adj_l[v].push_back(make_pair(w, u));
}

void dijkstra(int src){

	priority_queue<pii, vii, greater<pii> > pq;
	pq.push(make_pair(0, src));

	dist[src] = 0;

	while(!pq.empty()){
		int w = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if(dist[u] < w)
			continue;

		for(int i = 0; i < adj_l[u].size(); i++){
			int v = adj_l[u][i].second;
			int weight = adj_l[u][i].first;

			if(dist[v] > max(dist[u], weight)){
				dist[v] = max(dist[u], weight);
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}


int main(){
	//READ("LightOJ 1002.txt");
	int tc, case_no = 0, u, v, w ,src;
	cin>>tc;
	while(tc--){
		init();
		cin>>V>>E;
		rep(i, E){
			cin>>u>>v>>w;
			input(u, v, w);
		}
		cin>>src;
		dijkstra(src);
		printf("Case %d:\n", ++case_no);
		rep(i, V){
			(dist[i] == INF) ? printf("Impossible\n") : printf("%d\n", dist[i]);
		}
	}
	return 0;
}
