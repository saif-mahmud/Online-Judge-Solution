#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef vector <pii> vii;

#define INF 1000000000
#define MAXX 1000

int weight[MAXX][MAXX], dist[MAXX][MAXX];
int r, c;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void init(){
	for(int i = 0; i < MAXX; i++){
		for(int j = 0; j < MAXX; j++){
			weight[i][j] = 0;
			dist[i][j] = INF;
		}
	}
}

bool isValid(int tx, int ty){
	return ( (tx >= 0 && tx < r) && (ty >= 0 && ty < c) );
}

void dijkstra(pii src){

	priority_queue< iii,  vector<iii>, greater<iii> > pq;
	pq.push(make_pair(weight[src.first][src.second], src));

	dist[src.first][src.second] = weight[src.first][src.second];

	while(!pq.empty()){
        pii u = pq.top().second;
        pq.pop();

        int x = u.first;
        int y = u.second;

        for(int i = 0; i < 4; i++){
			int tx = x + dx[i];
			int ty = y + dy[i];

			if(isValid(tx, ty)){
				if(dist[tx][ty] > (dist[x][y] + weight[tx][ty]) ){
					dist[tx][ty] = (dist[x][y] + weight[tx][ty]);
					pq.push( make_pair( dist[tx][ty], make_pair(tx, ty) ) );
				}
			}
        }
	}
}

int main(){
	READ("UVa 929.txt");
	int tc, case_no = 0;
	scanf("%d", &tc);
	while(tc--){
		init();
		cin>>r>>c;

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cin>>weight[i][j];
			}
		}

		dijkstra(make_pair(0, 0));
		printf("%d\n", dist[r - 1][c - 1]);
	}
	return 0;
}
