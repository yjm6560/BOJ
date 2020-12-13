/*
	알바생 강호
	그리디
	난이도 1
*/
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	LL answer = (LL)0;
	cin >> N;
	vector<LL> tips(N);
	for(int i=0;i<N;i++)
		cin >> tips[i];
	sort(tips.rbegin(), tips.rend());
	for(int i=0;i<N;i++){
		if(i >= tips[i]){
			break;
		}
		answer += (LL)(tips[i] - i);
	}
	cout << answer << "\n";
}
