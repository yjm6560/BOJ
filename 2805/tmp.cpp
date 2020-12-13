#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int N, M, input;
vector<LL> trees, sums;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
//	trees.reserve(N);
//	sums.reserve(N);

	for(int i=0;i<N;i++){
		cin >> input;
		trees.push_back(input);
	}

	for(auto x : trees)
		cout << x << " ";
	cout << endl;


	sort(trees.begin(), trees.end());

	for(auto x : trees)
		cout << x << " ";
	cout << endl;
}
