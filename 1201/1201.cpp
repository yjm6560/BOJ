/*
	NMK
	그리디
	그냥 보고 함
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, K;
	cin >> N >> M >> K;

	if(M+K-1 > N || N > M*K){
		cout << "-1\n";
		return 0;
	}
	vector<int> nums;
	for(int i=1;i<=N;i++)
		nums.push_back(i);
	
	int idx = 0;

	for(int i=1;i<=M;i++){
		int temp = min(idx + K, N - M + i);
		reverse(nums.begin() + idx, nums.begin() + temp);
		idx = temp;
	}
	for(auto x : nums)
		cout << x << " ";
	cout << "\n";
}
