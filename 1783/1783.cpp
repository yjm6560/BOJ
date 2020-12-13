/*
	병든 나이트
	그리디
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long N, M, answer;

	cin >> N >> M;

	if(N == (ll)1){
		answer = (ll)1;
	}
	else if(N == (ll)2){
		answer = min((ll)4, (M+1)/2);
	}
	else {
		if(M >= (ll)7)
			answer = M - 2;
		else
			answer = min((ll)4, M);
	}
	cout << answer << endl;
}
