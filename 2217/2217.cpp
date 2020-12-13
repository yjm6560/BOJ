/*
	로프
	그리디
	난이도 1.5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, answer = 0;
	cin >> N;
	vector<int> rope(N);
	for(int i=0;i<N;i++)
		cin >> rope[i];

	sort(rope.begin(), rope.end());

	for(int i=0;i<rope.size();i++){
		int tmp = rope[i] * (rope.size() - i);
		answer = max(answer, tmp);
	}
	cout << answer << endl;
}
