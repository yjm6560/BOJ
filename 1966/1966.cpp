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

	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		queue<int> q;
		vector<int> priority(N);
		vector<bool> visited(N, false);
		for(int i=0;i<N;i++){
			cin >> priority[i];
			q.push(i);
		}
		for(int answer=1;answer<=N*N;answer++){
			visited[q.front()] = true;
			for(int i=0;i<N;i++){
				if(!visited[i] && priority[q.front()] < priority[i]){
					//push back
					q.push(q.front());
					visited[q.front()] = false;
					answer--;
					break;
				}
			}
			if(visited[M] && q.front() == M){
				cout << answer << "\n";
				break;
			}
			q.pop();
		}
	}


	return 0;
}
