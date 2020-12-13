/*
	
	그리디
	난이도 :
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
	int L, P, V, n = 1;
	while(true){
		cin >> L >> P >> V;
		if(L==0 && P==0 && V==0)
			break;
		cout << "Case " << n++ << ": " << L*(V/P) + min(L, V%P) << "\n";
	}
	return 0;
}
