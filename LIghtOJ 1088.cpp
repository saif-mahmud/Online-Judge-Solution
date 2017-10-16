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
	//READ("LightOJ 1088.txt");
	int tc, case_no = 0;
	scanf("%d", &tc);
	while(tc--){
		int n, q;
		scanf("%d %d", &n, &q);
		int pt[n];
		rep(i, n){
			scanf("%d", &pt[i]);
		}
		printf("Case %d:\n", ++case_no);
		int a, b;
		rep(i, q){
			scanf("%d %d", &a, &b);
			int l = lower_bound(pt, pt + n, a) - pt;
			int r = upper_bound(pt + l, pt + n, b) - pt;
			printf("%d\n", r - l);
		}
	}
	return 0;
}
