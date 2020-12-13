/*
	리모컨
	BFS
*/
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int N, M, input, beg = 100, dp[500001][7];
int dx[7] = {1000000, 100000, 10000, 1000, 100, 10, 1};
bool broken[10];
queue<int> q;


int main()
{
	cin >> N >> M;
	for(int i=0;i<10;i++)
		broken[input] = true;
	for(int i=0;i<M;i++){
		cin >> input;
		broken[input] = false;
	}
	for(int i=0;i<500001;i++)
		for(int j=0;j<7;j++)
			dp[i][j] = abs(i-beg);

	q.push(beg); q.push(1);

	while(!q.empty()){
		int x = q.front(); q.pop();
		int digit = q.front(); q.pop();
		if(x == N && digit == 6){
			cout << dp[x][6] << endl;
			return 0;
		}
		if(digit < 6){
			for(int i=0;i<10;i++){
				int nx = (x/dx[digit-1])*dx[digit-1] + digit*i;
				if(dp[nx][digit] != abs(nx - beg))
					continue;
				dp[nx][digit+1] = dp[x][digit] + 1;
				q.push(nx); q.push(digit+1);
			}
		}
		if(digit == 6){
			dp[x+1][6] = dp[x][6] + 1;
			q.push(x+1); q.push(digit);
			if(x != 0){
				dp[x-1][6] = dp[x][6] + 1;
				q.push(x-1);
				q.push(digit);
			}
		}
	}
}
