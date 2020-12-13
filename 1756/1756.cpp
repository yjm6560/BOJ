/*
	피자 굽기
	난이도
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

typedef long long ll;

using namespace std;

int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	
	ll D, N;
	cin >> D >> N;

	vector<ll> oven(D);
	vector<ll> pizza(N);
	for(int i=0;i<D;i++)
		cin >> oven[i];
	for(int i=0;i<N;i++)
		cin >> pizza[i];
	
}
