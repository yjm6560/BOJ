/*
	리모컨
	브루트 포스
*/
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int N, M, i, j, ret, input, beg = 100;
bool broken[10];

int main()
{
	cin >> N >> M;
	for(int i=0;i<10;i++)
		broken[input] = false;
	for(int i=0;i<M;i++){
		cin >> input;
		broken[input] = true;
	}
	ret = abs(N - beg);
	for(i=0;i<=1000000;i++){
		string s = to_string(i);
		for(j=0;j<s.length();j++){
			if(broken[s[j] - '0'])
				break;
		}
		if(j == s.length()){
			ret = min(ret, int(s.length() + abs(N - i)));
		}
	}
	cout << ret << endl;
}
