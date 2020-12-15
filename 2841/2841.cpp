#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define LINE_NUM 6
#define MAX_FRET 300000

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, P;
	cin >> N >> P;
	int answer = 0;
	vector<vector<int>> stack(LINE_NUM+1, vector<int>(1, 0));

	int line, fret;
	for(int i=0;i<N;i++){
		cin >> line >> fret;
		while(stack[line].back() > fret){
			stack[line].pop_back();
			answer++;
		}
		if(stack[line].back() != fret){
			stack[line].push_back(fret);
			answer++;
		}
	}
	cout << answer << endl;

	return 0;
}
