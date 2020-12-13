/*
	주식
	단순 구현
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
	
	int T;

	cin >> T;

	while(T--){
		long long N, answer = 0;
		cin >> N;
		vector<long long> stock(N);
		vector<long long> sellPrice(N, 0);

		for(int i=0;i<N;i++)
			cin >> stock[i];
		
		for(int i=N-2;i>=0;i--)
			sellPrice[i] = max(sellPrice[i+1], stock[i+1]);

		for(int i=0;i<N;i++)
			answer += max((sellPrice[i] - stock[i]), (long long)0);
		cout << answer << endl;
	}

	return 0;
}
