/*
	숫자 고르기
	알고리즘 : 그래프
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getCyclePath(int beg, int node, vector<int> nums, vector<int> &path){
	path.push_back(node);
	if(beg != nums[node])
		getCyclePath(beg, nums[node], nums, path);
}

int getCycleCount(int node, vector<int> nums, vector<int> &group_info, vector<int> &count_info, vector<int> &path){
	int next = nums[node];
	if(group_info[node] == group_info[next]){
		getCyclePath(node, node, nums, path);
		return count_info[node] - count_info[next] + 1;
	} else if(group_info[next] != -1){
		return 0;
	} else {
		group_info[next] = group_info[node];
		count_info[next] = count_info[node] + 1;
		return getCycleCount(next, nums, group_info, count_info, path);
	}
}

vector<int> solution(int N, vector<int> nums){
	vector<int> answer(1, 0);
	vector<int> group_info(N+1, -1), count_info(N+1, 0);
	vector<int> path;

	for(int i=1;i<=N;i++){
		if(group_info[i] == -1){
			group_info[i] = i;
			answer[0] += getCycleCount(i, nums, group_info, count_info, answer);
		}
	}
	sort(answer.begin()+1, answer.end());
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> nums(N+1);

	for(int i=1;i<=N;i++)
		cin >> nums[i];

	vector<int> result = solution(N, nums);
	for(int x : result)
		cout << x << "\n";
}
