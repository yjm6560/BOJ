/*
	이친수
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long N, bin_nums[91];
	cin >> N;
	bin_nums[1] = 1;
	bin_nums[2] = 2;
	for(int i=2;i<=N;i++)
		bin_nums[i] = bin_nums[i-1] + bin_nums[i-2];
	cout << bin_nums[N] << endl;
}
