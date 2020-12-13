/*
	30
	정수론, 그리디
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int sum = 0;
	cin >> s;
	for(char c : s)
		sum += c - '0';
	sort(s.begin(), s.end());
	
	if(s[0]=='0' && sum%3==0){
		for(int i=s.size()-1;i>=0;i--)
			cout << s[i];
		cout << "\n";
	}
	else {
		cout << "-1\n";
	}
}
