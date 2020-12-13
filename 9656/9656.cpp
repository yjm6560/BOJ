/*
	돌게임2
	DP
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	cout << (N%2? "CY\n" : "SK\n");
	
	return 0;
}
