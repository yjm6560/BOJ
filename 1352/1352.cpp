/*
	문자열
	그리디
	난이도 2.5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

bool idx[101];
vector<int> begList;
bool check = false;

void getIdx(int N, int cnt, int sum){
	if(check)
		return;
	if(sum == N){
		for(int i=1;i<=N;i++)
			if(idx[i])
				begList.push_back(i);
		check = true;
	} else if(sum > N){
		return;
	}
	for(int i=sum+1;i>cnt;i--){
		idx[i] = true;
		getIdx(N, i, sum+i);
		idx[i] = false;
	}
}
void solve(int N){
	memset(idx, 0, sizeof(idx));
	getIdx(N, 0, 0);
	if(begList.size()==0){
		cout << "-1\n";
		return;
	}
	vector<char> answer(N);
	vector<char> letter(26);
	queue<char> q;
	for(int i=0;i<26;i++)
		letter[i] = i+'A';
	for(int i=0, bIdx=0;i<N;i++){
		if(i==begList[bIdx]-1){
			answer[i] = letter[bIdx];
			for(int j=0;j<begList[bIdx]-1;j++){
				q.push(letter[bIdx]);
			}
			bIdx++;
		} else {
			answer[i] = q.front();
			q.pop();
		}
	}
	for(auto c : answer){
		cout << c;
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	solve(N);
}
