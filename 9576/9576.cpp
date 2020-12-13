/*
	책 나눠주기
	그리디, 네트워크 플로우, 이분 매칭, 최대 유량
	난이도 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b){
	return b.second > a.second;
	if(b.second == a.second)
		return b.first < a.first;
	return -1;
}

int solve(vector<pair<int, int>> books){
	int answer = 0;
	bool check[1001];
	memset(check, 0, sizeof(check));
	
	sort(books.begin(), books.end(), cmp);
	
	for(auto b : books){
		for(int i=b.first;i<=b.second;i++){
			if(!check[i]){
				check[i] = true;
				answer++;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		vector<pair<int, int>> books(M);
		for(int i=0;i<M;i++)
			cin >> books[i].first >> books[i].second;
		cout << solve(books) << "\n";
	}
}
