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
	//READ("UVa 410.txt");
	int tc, case_no = 0, c, s;

	while(scanf("%d %d", &c, &s) != EOF){

		vector <int> cm(2 * c, 0);

		int total_cm = 0;

		rep(i, s){
			scanf("%d", &cm[i]);
			total_cm += cm[i];
		}

		double avg_m = (double)total_cm / (double)c;

		sort(cm.begin(), cm.end());

		int res_cm[c];
		mem(res_cm, 0);

		printf("Set #%d\n", ++case_no);

		rep(i, c){
			printf(" %d:", i);

			if(cm[i]){
				printf(" %d", cm[i]);
				res_cm[i] += cm[i];
			}

			if(cm[(2 * c) - i - 1]){
				printf(" %d", cm[(2 * c) - i - 1]);
				res_cm[i] += cm[(2 * c) - i - 1];

			}

			printf("\n");
		}

		double imbalance = 0.0;

		rep(i, c){
			imbalance += abs(res_cm[i] - avg_m);
		}
		printf("IMBALANCE = %0.5lf\n\n", imbalance);
	}
	return 0;
}
