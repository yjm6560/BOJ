#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(0);

	int N, input, bef, max_val, max_val_sub, max_cnt, cnt;
	vector<int> nums;
	bool check = false;

	nums.reserve(N);

	cin >> N;
	for(int i=0;i<N;i++){
		cin >> input;
		nums.push_back(input);
	}
	
	sort(nums.begin(), nums.end());


	max_cnt = cnt = 1;
	bef = nums[N-1];
	max_val = bef;

	for(auto i=nums.end()-2;i>=nums.begin();i--){
		if(bef == *i){
			cnt++;
		} else {
			bef = *i;
			cnt = 1;
		}
		if(max_cnt == cnt){
			max_val_sub = max_val;
			check = true;
			max_val = *i;
			max_cnt = cnt;
		} else if(max_cnt < cnt){
			check = false;
			max_val = *i;
			max_cnt = cnt;
		}
	}

	cout << accumulate(nums.begin(), nums.end(), 0.0)/nums.size() << endl;
	cout << nums[N/2] << endl;
	cout << (check? max_val_sub : max_val) << endl;
	cout << nums[N-1] - nums[0] << endl;
}
