/*
	등수 매기기
	그리디
	난이도 1.5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long N, answer = 0;
	cin >> N;
	vector<long long> stu(N);
	for(int i=0;i<N;i++)
		cin >> stu[i];
	sort(stu.begin(), stu.end());

	for(long long i=1;i<=N;i++)
		answer += abs(i - stu[i-1]);
	cout << answer << endl;
}
