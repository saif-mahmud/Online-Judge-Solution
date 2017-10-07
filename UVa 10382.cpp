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

struct sprinkler{
	double x;
	double r;
	double left_range;
	double right_range;
};

bool checker(sprinkler s1, sprinkler s2){
	return s1.left_range < s2.left_range;
}

int main(){
	//READ("UVa 10382.txt");

	int n;
	double l, w;

	while(scanf("%d %lf %lf", &n, &l, &w) != EOF){
		sprinkler s[n];
		int t = 0;

		rep(i,n){
			scanf("%lf %lf", &s[i].x, &s[i].r);
			double b = (s[i].r * s[i].r) - ( (w/2) * (w/2) );
			if(b <= 0)
				continue;
			double dx = sqrt(b);
			s[t].left_range = s[i].x - dx;
			s[t].right_range = s[i].x + dx;
			t++;
		}

		sort(s, s + t, checker);

		/*printf("Interval Range : \n");
		rep(i, t){
			printf("[%0.3lf , %0.3lf]\n", s[i].left_range, s[i].right_range);
		}*/

		double currentLeft = 0.0, rightReach = 0.0;
		int cnt = 0;
		bool flag = false;

		if(s[0].left_range <= 0){
			int idx = 0;

			while(idx < t){
				int j = idx;
				while(s[j].left_range <= currentLeft && j < t){
					rightReach = max(rightReach, s[j].right_range);
					j++;
				}
				if(idx == j)
					break;
				idx = j;
				currentLeft = rightReach;
				cnt++;

				if(currentLeft >= l){
					flag = true;
					break;
				}
			}
		}

		if(flag)
			printf("%d\n", cnt);
		else
			printf("-1\n");
	}
	return 0;
}
