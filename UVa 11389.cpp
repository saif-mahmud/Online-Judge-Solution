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
	//READ("UVa 11389.txt");
	int n, d ,r;
	while(1){
		scanf("%d %d %d", &n, &d, &r);
		if(n == 0 && d == 0 && r == 0)
			break;

		int m[n], e[n];

		rep(i, n){
			scanf("%d", &m[i]);
		}
		rep(i, n){
			scanf("%d", &e[i]);
		}

		sort(m, m + n, greater<int>());
		sort(e, e + n);

		int total = 0;

		rep(i, n){
			int hrs = m[i] + e[i];
			if(hrs > d)
				total += ( ( hrs - d ) * r );
		}

		printf("%d\n", total);
	}
	return 0;
}
