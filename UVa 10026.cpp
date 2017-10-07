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

struct job{
    int jobID;
    int time;
    int fine;
};


bool checker(job a1, job a2){
    double r1 = (double) a1.fine / a1.time;
    double r2 = (double) a2.fine / a2.time;

    if(r1 == r2)
		return a1.jobID < a2.jobID;

	return r1 > r2;
}

int main(){
    //READ("UVa 10026.txt");

	int tc;
	scanf("%d", &tc);

	while(tc--){
		int n;
		scanf("%d", &n);

		vector<job> a(n);

		rep(i, n){
			a[i].jobID = i + 1;
			scanf("%d", &a[i].time);
			scanf("%d", &a[i].fine);
		}

		sort(a.begin(), a.end(), checker);

		printf("%d", a[0]);

		iter(i, 1, n){
			printf(" %d", a[i]);
		}
		printf("\n");

		if(tc)
			printf("\n");
	}

	return 0;
}


