/*
	퍼즐
	BFS
*/
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define MP make_pair

int ans = 123456789, puzzle = 0, cnt = 0;
int dx[4] = {-1, 1, -3, 3};

int main()
{
	int input;
	for(int i=0;i<9;i++){
		cin >> input;
		if(input == 0)
			input = 9;
		for(int j=1;j<9-i;j++)
			input *= 10;
		puzzle += input;
	}

	map<int, int> visited;
	queue<int> q;
	q.push(puzzle);
	visited.insert(MP(puzzle, 0));

	while(!q.empty()){
		if(q.front() == ans){
			cout << visited.find(ans)->second << endl;
			return 0;
		}

		string s = to_string(q.front()); q.pop();
		int blank = s.find("9");
		
		for(int i=0;i<4;i++){
			int nb = blank + dx[i];
			if(nb<0 || nb>8)
				continue;
			if(dx[i]==-1 && nb%3 == 2)
				continue;
			if(dx[i]==1 && nb%3 == 0)
				continue;

			string tmp = s;
			tmp[nb] = '9';
			tmp[blank] = s[nb];
			int next = atoi(tmp.c_str());
			if(visited.count(next))
				continue;
			visited.insert(MP(next, visited.find(atoi(s.c_str()))->second + 1));
			q.push(next);
		}
	}
	cout << "-1\n";
}

