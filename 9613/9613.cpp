/*
	GCD 합
	수학
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long T, n, ret, ans, x, y, nums[100];
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> nums[i];
		ret = 0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans = 1;
				x = nums[i];
				y = nums[j];
				for(int a=2;a<=min(x, y);a++){
					if(!(x%a) && !(y%a)){
						x /= a;
						y /= a;
						ans *= a;
						a--;
					}
				}
				ret += ans; 
			}
		}
		cout << ret << "\n";
	}
}
