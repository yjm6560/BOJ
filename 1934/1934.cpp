/*
	최소공배수
	수학
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, x, y, ans;
	cin >> T;

	while(T--){
		cin >> x >> y;
		ans = 1;
		for(int i=2;i<=min(x, y);i++){
			if(!(x%i) && !(y%i)){
				x /= i;
				y /= i;
				ans *= i;
				i--;
			}
		}
		cout << ans*x*y << "\n";
	}
}
