#include <iostream> 
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;

LL N, M, input;
vector<LL> trees, sums;

LL solve(LL x, LL y){
	if(x == y)
		return x;
	LL mid = (x + y)/2;
	if(M >= sums[mid]){
		return solve(x, mid);
	} else {
		return solve(mid+1, y);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for(int i=0;i<N;i++){
		cin >> input;
		trees.push_back(input);
		sums.push_back(0);
	}
	
	sort(trees.begin(), trees.end());

	sums[N-1] = 0;
	for(int i=N-2;i>=0;i--)
		sums[i] = sums[i+1] + (trees[i+1] - trees[i])*(N - i - 1);	
	
	int idx = solve(0, N-1);
	int remains = N - idx;
	int answer = 0;
	for(;sums[idx]+answer*remains < M;answer++);
	cout << trees[idx] - answer << endl;
	
	return 0;
}
