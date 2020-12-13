#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int S;
	const int INF = 987654321;
	priority_queue<pair<int, int>> q;
	cin >> S;
	vector<bool> visited(S*2 + 1, false);
	
	q.push({0, 1});
	while(!q.empty()){
		int t = q.top().first;
		int x = q.top().second;
		q.pop();
		visited[x] = true;
		if(x == S){
			cout << -t << endl;
			return 0;
		}
		if(x>2 && !visited[x-1]) {
			q.push({t-1, x-1});
		}
		for(int i=x*2;i<=S*2;i+=x){
			if(!visited[i]){
				q.push({t-(i/x), i});
			}
		}
	}
	
	return 0;
}
