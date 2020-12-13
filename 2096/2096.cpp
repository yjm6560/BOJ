/*
	내려가기
	알고리즘 : DP
	난이도 : 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, max_answer, min_answer;
	cin >> N;
	vector<int> lines(3, 0);
	vector<int> dp1(3, 0), dp2(3, 0);
	vector<int> tmp1(3, 0), tmp2(3, 0);
	
	for(int i=0;i<3;i++)
		cin >> lines[i];

	for(int i=0;i<N;i++){
		tmp1[0] = lines[0] + max(dp1[0], dp1[1]);
		tmp1[1] = lines[1] + max(dp1[0], max(dp1[1], dp1[2]));
		tmp1[2] = lines[2] + max(dp1[1], dp1[2]);
		tmp2[0] = lines[0] + min(dp2[0], dp2[1]);
		tmp2[1] = lines[1] + min(dp2[0], min(dp2[1], dp2[2]));
		tmp2[2] = lines[2] + min(dp2[1], dp2[2]);
		for(int j=0;j<3;j++){
			dp1[j] = tmp1[j];
			dp2[j] = tmp2[j];
			cin >> lines[j];
		}
	}
	max_answer = max(dp1[0], max(dp1[1], dp1[2]));
	min_answer = min(dp2[0], min(dp2[1], dp2[2]));

	cout << max_answer << " " << min_answer << endl;
}
