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


double obtainedRatio(double ab, double ac, double bc, double ad){
	double ae = (ad * ac) / ab;
	double de = (ad * bc) / ab;

	double s_large = (ab + bc + ac) / 2.0;
	double s_small = (ad + de + ae) / 2.0;

	double large_triangle = sqrt(s_large * (s_large - ab) * (s_large - bc) * (s_large - ac));
	double small_triangle = sqrt(s_small * (s_small - ad) * (s_small - de) * (s_small - ae));

	double traphezium = large_triangle - small_triangle;

	return small_triangle / traphezium;
}

double bisection(double ab, double ac, double bc, double givenRatio){
	double low = 0.0;
	double high = ab;

	double mid, ad;

	rep(i, 100){
		mid = (low + high) / 2.0;
		ad = mid;

		if(obtainedRatio(ab, ac, bc, ad) > givenRatio)
			high = mid;
		else
			low = mid;
	}

	return ad;
}


int main(){
	//READ("LightOJ 1043.txt");
	int tc, case_no = 0;
	cin>>tc;
	while(tc--){
		double ab, ac, bc, givenRatio;
		cin>>ab>>ac>>bc>>givenRatio;
		double ans = bisection(ab, ac, bc, givenRatio);
		printf("Case %d: %lf\n", ++case_no, ans);
	}
	return 0;
}
