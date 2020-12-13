/*
	요세푸스 문제
	큐
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, cur = -1, cnt, check = 0;
	vector<int> circle, answer;
	cin >> n >> k;

	for(int i=1;i<=n;i++)
		circle.push_back(i);
	while(check < n){
		cnt = 0;
		while(cnt != k){
			cur = (cur+1)%n;
			if(circle[cur]){
				cnt++;
			}
		}
		answer.push_back(circle[cur]);
		circle[cur] = 0;
		check++;
	}
	cout << "<";
	for(int i=0;i<n-1;i++)
		cout << answer[i] << ", ";
	cout << answer[n-1] << ">\n";
}
