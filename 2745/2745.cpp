/*
	진법 변환
	수학
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int B, answer = 0;
	string s;
	cin >> s >> B;
	for(int i=0;s[i];i++){
		answer *= B;
		if(s[i] >= '0' && s[i] <= '9')
			answer += s[i] - '0';
		else
			answer += 10 + s[i] - 'A';
	}
	cout << answer << endl;
}
