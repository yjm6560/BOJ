#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, input_front, input_back;
	cin >> N >> M;
	vector<vector<int>> order(N+1, vector<int>(0));
	vector<int> inCount(N+1, 0);
	queue<int> q;

	for(int i=0;i<M;i++){
		cin >> input_front >> input_back;
		order[input_front].push_back(input_back);
		inCount[input_back]++;
	}

	for(int i=1;i<=N;i++)
		if(inCount[i] == 0)
			q.push(i);
	
	for(int i=0;i<N;i++){
		for(auto x : order[q.front()])
			if(--inCount[x] == 0)
				q.push(x);

		order[q.front()].clear();

		cout << q.front() << " ";

		q.pop();
	}

	cout << endl;

	return 0;
}
