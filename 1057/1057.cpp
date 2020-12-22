#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K, L, answer = 0;
	cin >> N >> K >> L;
	K--; L--;
	while(K != L){
		K /= 2;
		L /= 2;
		answer++;
	}
	cout << answer << endl;
	return 0;
}
