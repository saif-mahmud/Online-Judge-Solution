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
	//READ("UVa 11057.txt");

	int n, m;

	while(scanf("%d", &n) != EOF){
		int b[n];

		rep(i, n)
			scanf("%d", &b[i]);

		sort(b, b + n);

		scanf("%d", &m);

		int i = 0, j = n - 1;

		int res_i, res_j;

		while(i < j){
			if(b[i] + b[j] < m)
				i++;

			else if(b[i] + b[j] == m){
				res_i = i;
				res_j = j;
				i++;
				j--;
			}

			else
				j--;
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", b[res_i], b[res_j]);
	}
	return 0;
}
