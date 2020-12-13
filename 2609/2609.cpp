/*
	최대공약수와 최소공배수
	수학
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, min_ans = 1;
	cin >> x >> y;
	
	for(int i=2;i<=min(x, y);i++){
		if(!(x%i) && !(y%i)){
//			cout << i << " " << x << " " << y << endl;
			x /= i;
			y /= i;
			min_ans *= i;
			i--;
		}
	}
//	cout << x << " " << y << endl;
	cout << min_ans << "\n" << min_ans*x*y << endl;
}
