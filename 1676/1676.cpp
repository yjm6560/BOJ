/*
	팩토리얼 0의 개수
	수학
*/
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

inline int howMany(int x, int y){
	if(y%x)
		return 0;
	return howMany(x, y/x) + 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, cnt2 = 0, cnt5 = 0;
	cin >> N;
	
	for(int i=2;i<=N;i++){
		cnt2 += howMany(2, i);
		cnt5 += howMany(5, i);
	}
	cout << min(cnt2, cnt5) << endl;
}
