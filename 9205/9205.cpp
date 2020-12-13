/*
	맥주 마시면서 걸어가기
	BFS
*/

#include <iostream>
#include <queue>

using namespace std;

#define MAX_WALK 1000
#define dist(x1, y1, x2, y2) (abs((x1)-(x2)) + abs((y1)-(y2)))

void bfs(){
	int N, x[102], y[102];
	bool visited[102];
	queue<int> q;

	cin >> N;
	
	for(int i=0;i<=N+1;i++){
		cin >> x[i] >> y[i];
		visited[i] = false;
	}
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=1;i<=N+1;i++){
			if(visited[i])
				continue;
			if(dist(x[cur], y[cur], x[i], y[i]) > MAX_WALK)
				continue;
			visited[i] = true;
			q.push(i);
		}
	}
	if(visited[N+1])
		cout << "happy\n";
	else
		cout << "sad\n";
	return;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		bfs();
}
