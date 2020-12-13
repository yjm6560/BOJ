/*
	암호 만들기
	백트래킹
	난이도 2.5
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>

#define getIdx(x) (x-'a')

using namespace std;
int L, C, j_cnt = 0, m_cnt = 0;
vector<char> code;
vector<char> answer;
map<char, bool> moum;

void solve(int idx){
	if(answer.size() == L){
		if(j_cnt>=2 && m_cnt>=1){
			for(auto c : answer)
				cout << c;
			cout << "\n";
			return;
		}
		return;
	}
	if(idx == code.size())
		return;
	for(int i=idx;i<C;i++){
		answer.push_back(code[i]);
		if(moum[code[i]])
			m_cnt++;
		else
			j_cnt++;

		solve(i+1);
		
		answer.pop_back();
		if(moum[code[i]])
			m_cnt--;
		else
			j_cnt--;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	moum.insert({'a', 1});
	moum.insert({'e', 1});
	moum.insert({'i', 1});
	moum.insert({'o', 1});
	moum.insert({'u', 1});
	
	cin >> L >> C;
	char x;
	for(int i=0;i<C;i++){
		cin >> x;
		code.push_back(x);
	}
	sort(code.begin(), code.end());

	solve(0);
}
