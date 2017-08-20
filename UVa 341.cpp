#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define rep(i,n) for(int i = 1 ; i <= (n) ; i++)
#define iter(i,a,b) for(int i = (a) ; i < (b) ; i++)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef vector <pii> vii;

#define INF 1000000000
#define MAXX 15

int V, E;
int adj_m[MAXX][MAXX], par[MAXX][MAXX];

void init()
{
    rep(i, MAXX)
    {
        rep(j, MAXX)
        {
            adj_m[i][j] = INF;
            par[i][j] = i;
        }
    }
}

void floyd_warshall()
{
    rep(k, V)
    {
        rep(i, V)
        {
            rep(j, V)
            {
                if(adj_m[i][j] > (adj_m[i][k] + adj_m[k][j]) )
                {
                    adj_m[i][j] = (adj_m[i][k] + adj_m[k][j]);
                    par[i][j] = par[k][j];
                }
            }
        }
    }
}

void printPath(int i, int j)
{
    if(i != j)
        printPath(i, par[i][j]);
    printf(" %d", j);
}

int main()
{
    READ("UVa 341.txt");
    int tc, case_no = 0, v, w, n, src, dest;
    while(true){
		init();
		cin>>V;
		if(V == 0)
			break;
		for(int u = 1; u <= V; u++){
			cin>>n;
			for(int j = 0; j < n; j++){
				cin>>v>>w;
				adj_m[u][v] = w;
			}
		}
		cin>>src>>dest;
		floyd_warshall();
		printf("Case %d: Path =", ++case_no);
		printPath(src, dest);
		printf("; %d second delay", adj_m[src][dest]);
		printf("\n");
    }
    return 0;
}
