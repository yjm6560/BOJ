/*
	조합 0의 개수
	수학
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n, m;

long long solve(long long x, long long y){
	if(y/x == 0)
		return 0;
	return solve(x, y/x) + y/x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> m;
	
	cout << min(solve(2, n) - solve(2, m) - solve(2, n-m) , solve(5, n) - solve(5, m) - solve(5, n-m)) << endl;
//	cout << min(solve(2, n), solve(5, n)) - min(solve(2, m), solve(5, m)) - min(solve(2, n-m), solve(5, n-m)) << endl;

}
