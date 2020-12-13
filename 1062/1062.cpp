/*
	가르침

	난이도
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K, answer = 0;
	vector<int> alpha(26);
	cin >> N >> K;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		for(char c : s){
			alpha[c-'a']++;
		}
	}
	sort(alpha.rbegin(), alpha.rend());
	for(int i=0;i<K;i++)
		answer += alpha[i];
	cout << answer << endl;
}
