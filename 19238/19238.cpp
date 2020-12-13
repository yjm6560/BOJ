/*
	스마트택시
	알고리즘
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

#define INF 987654321

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int moveToClient(int N, int M, vector<vector<int>> &road, vector<int> &taxi_pos){
	/*
		우선순위 큐 사용해서 다음 손님 찾기
		{-(행 번호), -(열 번호)}
		이렇게 넣으면 작은 것부터 빼기 가능
		여기서 answer는 손님과의 최소 거리를 의미
		bfs기 때문에 이 answer보다 거리가 먼 노드들은 방문할 의미가 없음

	*/
	int answer = INF;
	//우선순위 큐에는 다음 방문할 손님 후보들이 들어감
	priority_queue<pair<int, int>> next_clients;

	//노드 방문을 위한 큐
	queue<pair<int, int>> q;

	//거리 계산을 위한 dist 맵
	vector<vector<int>> dist(N+1, vector<int>(N+1, INF));

	//시작점 세팅
	dist[taxi_pos[0]][taxi_pos[1]] = 0;
	
	//시작점이 다른 손님의 출발지면 거리 0 리턴, 택시 좌표는 변경할 필요 없음
	if(road[taxi_pos[0]][taxi_pos[1]] < 0)
		return 0;

	//손님 찾기 시작!
	q.push({taxi_pos[0], taxi_pos[1]});
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//이제 기준 노드가 answer(최소 승객 거리)와 같아지면 더이상 다른 노드를 방문하는 의미가 없음(다 얘보다 멀리 있기 때문)
		if(dist[x][y] >= answer)
			break;
		for(int d=0;d<4;d++){
			int nx = x + dx[d];
			int ny = y + dy[d];

			if(nx==0 || nx>N || ny==0 || ny>N)
				continue;

			//벽이거나 방문했던 노드면 continue
			if(road[nx][ny]==1 || dist[nx][ny]<INF)
				continue;

			//승객이 있으면 answer 설정해주기 + 다음 승객 후보에 넣어주기
			if(road[nx][ny]<0){
				answer = dist[x][y] + 1;
				next_clients.push({-nx, -ny});
			}
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}
	}
	//승객을 구했으면 택시 이동 후 이동 거리 return
	if(answer < INF){
		taxi_pos[0] = -next_clients.top().first;
		taxi_pos[1] = -next_clients.top().second;
	}
	return answer;
}


int moveToDst(int N, int M, int client, vector<vector<int>> &road, vector<int> &taxi_pos, vector<vector<int>> client_pos){
	/*
		승객의 목적지로 이동하기
		client 매개변수가 승객 번호
		client_pos의 2,3 번째 원소가 목적지 x, y좌표이므로 여기까지 가는 길을 찾으면 됨
		대체로 moveToClient와 비슷
	*/
	int answer = INF;
	queue<pair<int, int>> q;
	vector<vector<int>> dist(N+1, vector<int>(N+1, INF));
	dist[taxi_pos[0]][taxi_pos[1]] = 0;
	q.push({taxi_pos[0], taxi_pos[1]});
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int d=0;d<4;d++){
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(nx==0 || nx>N || ny==0 || ny>N)
				continue;
			if(road[nx][ny]==1 || dist[nx][ny]<INF)
				continue;
			if(nx==client_pos[client][2] && ny==client_pos[client][3]){
				taxi_pos[0] = nx;
				taxi_pos[1] = ny;
				return dist[x][y] + 1;
			}
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}
	}
	return INF;
}
int solution(int N, int M, int fuel, vector<vector<int>> road, vector<int> taxi_pos, vector<vector<int>> client_pos){
	/*
	   1. 택시로부터 승객들과의 거리를 계산
	   2. 가장 가까운 승객에게 이동(거리, 행, 열 우선순위)
	   3. 목적지 이동이 가능하면 5번으로 
	   4. 목적지 이동이 불가능하면 -1 return 
	   5. 이동 후 연료 충전
	   6. 연료가 떨어졌으면 -1 return
	   7. 연료 안 떨어졌으면 다시 1번으로
	*/
	//answer 가 앞으로 fuel (어차피 fuel 리턴할 거니까)
	int answer = fuel;

	//road에 출발 client 새기기
	// 마이너스 1 곱해서 기록해줌으로써 1로 새겨진 벽과 분리
	for(int i=0;i<client_pos.size();i++){
		road[client_pos[i][0]][client_pos[i][1]] = -i;
	}
	//M명 태워야 되니까 M번 for문 돌기
	for(int i=0;i<M;i++){
		int dist, client;
		// 손님 태우러 가기
		// dist = 간 거리
		dist = moveToClient(N, M, road, taxi_pos);
		
		//fuel 보다 간 거리가 같거나 길면 return -1
		if(answer <= dist)
			return -1;
		//간 거리만큼 fuel에서 빼주기
		answer -= dist;

		//내가 태운 손님. 얘를 목적지까지 데려다주기
		client = -road[taxi_pos[0]][taxi_pos[1]];

		//태웠으니까 road에서 지워주기
		road[taxi_pos[0]][taxi_pos[1]] = 0;

		//데려다준 거리 찾기
		dist = moveToDst(N, M, client, road, taxi_pos, client_pos);

		//fuel 보다 간 거리가 길면 return -1
		if(answer < dist){
			return -1;
		}

		//연료 충전해주기. 간 거리를 안 빼주기 때문에 그냥 dist 한 번만 더해주면 됨
		answer += dist;
	}
	return answer;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, fuel;
	cin >> N >> M >> fuel;
	vector<vector<int>> road(N+1, vector<int>(N+1, 0));
	vector<int> taxi_pos(2);
	vector<vector<int>> client_pos(M+1, vector<int>(4));
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin >> road[i][j];
	cin >> taxi_pos[0] >> taxi_pos[1];
	for(int i=1;i<=M;i++){
		for(int j=0;j<4;j++){
			cin >> client_pos[i][j];
		}
	}
	cout << solution(N, M, fuel, road, taxi_pos, client_pos) << "\n";
}
