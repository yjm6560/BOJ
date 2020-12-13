/*	
	나무 위의 벌레
	알고리즘
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fruit(10001, 0), dp(10001, -1);

int solution(int parent, int child, vector<vector<int>> tree){
	if(parent != -1 && dp[child] != -1)
		return dp[child];
	
	dp[child] = fruit[child];
	for(auto next : tree[child])
		if(parent != next)
			dp[child] = max(dp[child], fruit[child] + solution(child, next, tree));
	return dp[child];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, answer = 0, root = 0;
	cin >> N;
	vector<vector<int>> tree(N+1);
	int a, b;
	for(int i=1;i<=N;i++)
		cin >> fruit[i];
	for(int i=1;i<N;i++){
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vector<int> sum(N+1);
	sum[N] = fruit[N];
	for(int i=N-1;i>=1;i--)
		sum[i] = sum[i+1] + fruit[i];
	for(int i=1;i<=N;i++){
		int result = solution(-1, i, tree);
		if(answer < result){
			answer = result;
			root = i;
		}
		if(answer >= sum[i])
			break;
	}
	for(int i=1;i<=N;i++)
		cout << i << "st : " << dp[i] << endl;
	cout << answer << " " << root << endl;
}
