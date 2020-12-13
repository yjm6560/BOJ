/*
	Generations of Tribbles
	DP
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
	
	vector<long long> koong(68, 1);
	koong[2] = 2;
	koong[3] = 4;

	for(int i=4;i<=67;i++)
		koong[i] = koong[i-1] + koong[i-2] + koong[i-3] + koong[i-4];
	
	int T, k;
	cin >> T;
	while(T--){
		cin >> k;
		cout << koong[k] << "\n";
	}
	return 0;
}
