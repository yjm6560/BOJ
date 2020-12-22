#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long N, answer = 1;
	cin >> N;
	vector<int> chu(N);
	
	for(int i=0;i<N;i++)
		cin >> chu[i];

	sort(chu.begin(), chu.end());
	
	if(chu[0] == 1)
		for(int i=1;i<N && (answer+1)>=chu[i];i++)
			answer += chu[i];
	else
		answer = 0;

	cout << answer + 1 << endl;

	return 0;
}
