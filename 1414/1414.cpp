/*
	불우이웃돕기
	그리디, 그래프 이론
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <numeric>

#define MAX 101

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, answer=0;
	string input;
	cin >> N;
	int room[MAX][MAX];
	memset(room, 0, sizeof(room));

	for(int i=0;i<N;i++){
		cin >> input;
		for(int j=0;j<N;j++){
			if(input[j]=='0')
				room[i][j] = 0;
			else if(input[j]>='a' && input[j]<='z')
				room[i][j] = input[j] - 'a' + 1;
			else if(input[j]>='A' && input[j]<='Z')
				room[i][j] = input[j] - 'A' + 1;
			answer += room[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)
				room[i][j] = 0;
			room[i][j] = min(room[i][j], room[j][i]);
			room[j][i] = room[i][j];
			cout << room[i][j] << " ";
		}
		cout << endl;
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i==j || i==k || j==k)
					continue;
				room[i][j] = min(room[i][j], room[i][k]+room[k][j]);
				room[j][i] = min(room[j][i], room[j][k]+room[k][i]);

			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << room[i][j] << " ";
		}
		cout << endl;
	}
}
