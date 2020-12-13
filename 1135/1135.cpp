/*
   뉴스 전하기
   트리
*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

#define PB push_back

int N, input;
vector<vector<int>> company;

int in_order(int node){
	vector<int> ret;
	int max_val = 0;

	for(auto x : company[node])
		ret.PB(in_order(x));

	sort(ret.begin(), ret.end(), greater<int>());

	for(int i=0;i<ret.size();i++)
		max_val = max(max_val, i+ret[i]+1);
	return max_val;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	company.reserve(50);

	cin >> N;
	cin >> input;

	for(int i=0;i<N;i++){
		vector<int> tmp;
		company.PB(tmp);
	}
	for(int i=1;i<N;i++){
		cin >> input;
		company[input].PB(i);
	}
	cout << in_order(0) << endl;
}
