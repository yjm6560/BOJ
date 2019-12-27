#include <iostream>

using namespace std;

int T, n, ret[12] = {0, 1, 2, 4}, nums[3] = {1, 2, 3};

int main()
{
	cin >> T;
	for(int i=4;i<=11;i++)
		ret[i] = ret[i-1]+ret[i-2]+ret[i-3];
	while(T--){
		cin >> n;
		cout << ret[n] << "\n";
	}
}
