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
	//READ("UVa 10763.txt");

	while(1){
		int n;
		scanf("%d", &n);
		if(n == 0)
			break;

		int a[n], b[n];

		rep(i, n){
			scanf("%d %d", &a[i], &b[i]);
		}

		sort(a, a + n);
		sort(b, b + n);

		int cnt = 0;

		rep(i, n){
			if(a[i] != b[i])
				break;
			cnt++;
		}

		if(cnt == n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
