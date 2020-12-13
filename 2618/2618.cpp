/*
	DP
	2 police cars
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long ll;

#define MP make_pair 
#define F first
#define S second
#define dist(pos1, pos2) abs(pos2.F-pos1.F)+abs(pos2.S-pos1.S)

vector<pair<ll, ll>> dest;
vector<pair<ll, ll>> path;
ll N, W, S, E, ans;
pair<ll, pair<ll, ll>> dp[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> W;
	for(ll i=0;i<W;i++){
		cin >> S >> E;
		dest.push_back(MP(S,E));
		dp[i][i].F = LLONG_MAX;
	}
	dp[0][1] = MP(dist(MP(N,N), dest[0]), MP(0,0));
	dp[1][0] = MP(dist(MP(1,1), dest[0]), MP(0,0));

	for(ll i=1;i<W;i++){
		dp[i][i+1].F = dp[i][0].F + dist(MP(N,N), dest[i]);
		dp[i][i+1].S = MP(i,0);
		dp[i+1][i].F = dp[0][i].F + dist(MP(1,1), dest[i]);
		dp[i+1][i].S = MP(0,i);
		for(int j=0;j<i;j++){
			dp[j][i+1].F = dp[j][i].F + dist(dest[i-1], dest[i]);
			dp[i+1][j].F = dp[i][j].F + dist(dest[i-1], dest[i]);
			dp[j][i+1].S = MP(j,i);
			dp[i+1][j].S = MP(i,j);
			if(j>0){
				if(dp[i][i+1].F > dp[i][j].F + dist(dest[j-1], dest[i])){
					dp[i][i+1].F = dp[i][j].F + dist(dest[j-1], dest[i]);
					dp[i][i+1].S = MP(i,j);
				}
				if(dp[i+1][i].F > dp[j][i].F + dist(dest[j-1], dest[i])){
					dp[i+1][i].F = dp[j][i].F + dist(dest[j-1], dest[i]);
					dp[i+1][i].S = MP(j,i);
				}
			}
		}
	}
	ans = dp[W][0].F;
	
	ll r = W;
	ll c = 0;
	for(ll i=0;i<W;i++){
		if(ans > dp[W][i].F){
			ans = dp[W][i].F;
			r = W;
			c = i;
		}
		if(ans > dp[i][W].F){
			ans = dp[i][W].F;
			r = i;
			c = W;
		}
	}
	cout << ans << endl;
	path.push_back(MP(r,c));
	while(r != 0 && c != 0){
		ll tmp_r = dp[r][c].S.F;
		ll tmp_c = dp[r][c].S.S;
		r = tmp_r;
		c = tmp_c;
		pair<int, int> tmp = path[path.size()-1];
		if(tmp.F > r && r > c)
			continue;
		if(tmp.S > c && c > r)
			continue;
		path.push_back(MP(r,c));
	}
	for(ll i=path.size()-1;i>=0;i--){
		for(ll j=0;j<abs(path[i].S-path[i].F);j++)
			cout << (path[i].S > path[i].F ? 2 : 1) << "\n";
	}
}
