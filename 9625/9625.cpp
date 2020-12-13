#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int K;
	cin >> K;
	vector<int> dp_A(K+1, 0), dp_B(K+1,0);
	
	dp_A[0] = 1;
	for(int i=1;i<=K;i++){
		dp_A[i] = dp_B[i-1];
		dp_B[i] = dp_A[i-1] + dp_B[i-1];
	}
	cout << dp_A[K] << " " << dp_B[K] << endl;

	return 0;
}
