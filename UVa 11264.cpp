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
	//READ(".txt");
	int tc, case_no = 0;
	cin>>tc;
	while(tc--){
		int n;
		scanf("%d", &n);
		int c[n];
		rep(i, n){
			scanf("%d", &c[i]);
		}
		int total = 0, cnt = 0;
		rep(i, n - 1){
			if( (total + c[i]) < c[i + 1] ){
				total += c[i];
				cnt++;
			}
		}
		cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
