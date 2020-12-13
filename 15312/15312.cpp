/*
	이름 궁합
	?
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int> nums){
	if(nums.size() == 2)
		return nums;
	vector<int> answer;
	for(int i=0;i<(int)nums.size()-1;i++)
		answer.push_back((nums[i]+nums[i+1])%10);

	return solve(answer);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> cnt = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

	string jm, jh;
	cin >> jm >> jh;
	
	vector<int> nums;
	for(int i=0;i<jm.length();i++){
		nums.push_back(cnt[jm[i] - 'A']);
		nums.push_back(cnt[jh[i] - 'A']);
	}
	vector<int> result = solve(nums);
	for(auto r : result)
		cout << r;
	cout << endl;

	return 0;
}
