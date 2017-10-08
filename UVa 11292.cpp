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

int main(){
	//READ("UVa 11292.txt");
	while(1){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0)
			break;
		int dragon[n], knight[m];
		rep(i, n){
			scanf("%d", &dragon[i]);
		}
		rep(i, m){
			scanf("%d", &knight[i]);
		}
		sort(dragon, dragon + n);
		sort(knight, knight + m);

		int gold = 0, d = 0, k = 0;

		while(d < n && k < m){
			while(dragon[d] > knight[k] && k < m)
				k++;
			if(k == m)
				break;
			gold += knight[k];
			d++;
			k++;
		}
		if(d == n)
			printf("%d\n", gold);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}
