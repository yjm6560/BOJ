/*
	대회 or 인턴
	그리디
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, K, ret;
	cin >> N >> M >> K;
	for(int t=0;t<=min(N/2, M);t++)
		if(N + M - 3*t >= K)
			ret = t;
	cout << ret << endl;
}
