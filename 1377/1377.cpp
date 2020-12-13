/*
	버블 소트
	정렬
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, answer = 0;
	cin >> N;
	vector<pair<int, int>> arr(N);
	
	for(int i=0;i<N;i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end());
	
	for(int i=0;i<N;i++)
		answer = max(answer, arr[i].second - i);

	cout << answer + 1 << endl;
}
