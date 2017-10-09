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
	//READ("UVa 11369.txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		int n;
		scanf("%d", &n);

		int p[n];

		rep(i, n){
			scanf("%d", &p[i]);
		}

		sort(p, p + n, greater<int>());

		int res = 0;
		if(n >= 3){
			for(int i = 2; i < n - (n % 3); i += 3)
				res += p[i];
			printf("%d\n", res);
		}
		else
			printf("0\n");
	}
	return 0;
}
