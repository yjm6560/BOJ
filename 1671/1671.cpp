/*
	상어의 저녁식사
	네트워크 플로우, 이분 매칭, 최대 유량, 그래프 이론
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <numeric>

typedef long long LL;

using namespace std;
int N, answer = 0;
vector<vector<LL>> sharks(50, vector<LL>(3));
vector<LL> bigList(N);
bool dead[50] = {0};

bool cmp(vector<LL> a, vector<LL> b){
	if(a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2])
		return true;
	else
		return false;
//	return (accumulate(b.begin(), b.end(), 0)
		- accumulate(a.begin(), a.end(), 0)) > 0;
}

LL dp(int a){
	if(dead[a])
		return 0;
	for(int cnt=0,b=0;b<bigList[a].size()&&cnt<2;b++){
		if(cmp(sharks[a], sharks[b]) && !dead[b]){
			alive[b] = false;
			dp(a+1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	sharks.resize(N);

	for(int i=0;i<N;i++)
		cin >> sharks[i][0] >> sharks[i][1] >> sharks[i][2];
	
	sort(sharks.begin(), sharks.end(), cmp);
	for(int i=N-1;i>=0;i--){
		for(int j=0;j<N;j++){
			if(i==j)
				continue;
			//cout << i << " " << j << " : " << getGap(sharks[i], sharks[j]) << endl;
			if(cmp(sharks[i], sharks[j]))
				bigList[i].push_back(j);
		}
	cout << answer << endl;
//	for(auto shark : sharks) cout << shark[0] << " " << shark[1] << " " << shark[2] << endl;
}
