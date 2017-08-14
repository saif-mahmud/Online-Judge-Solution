#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define MAXX 20001
#define INF 538976288

vector< pair<int, int> > adj_l[MAXX];
int dist[MAXX];
int V, E;

void init(){
	for(int i = 0; i < MAXX; i++)
		adj_l[i].clear();
	mem(dist, INF);
}

void input(int u, int v, int w){
	adj_l[u].push_back(make_pair(w, v));
	adj_l[v].push_back(make_pair(w, u));
}

void dijkstra(int src){
	priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	pq.push(make_pair(0, src));

	dist[src] = 0;

	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();

		for(int i = 0; i < adj_l[u].size(); i++){
			int v = adj_l[u][i].second;
			int weight = adj_l[u][i].first;

			if(dist[v] > (dist[u] + weight)){
				dist[v] = (dist[u] + weight);
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

int main(){
	READ("UVa 10986.txt");
	int tc, case_no = 0, u, v, w, src, dest;
	scanf("%d", &tc);
	while(tc--){
		init();
		scanf("%d %d %d %d", &V, &E, &src, &dest);
		for(int i = 0; i < E; i++){
			scanf("%d %d %d", &u, &v, &w);
			input(u, v, w);
		}
		dijkstra(src);

		if(dist[dest] == INF)
			printf("Case #%d: unreachable\n", ++case_no);
		else
			printf("Case #%d: %d\n", ++case_no, dist[dest]);
	}
	return 0;
}
