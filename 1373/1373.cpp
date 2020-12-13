/*
	2진수 8진수
	수학
*/
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string bin;
	int len, arr[3] = {1, 2, 4};
	
	cin >> bin;
	len = bin.length();
	vector<int> answer;

	for(int i=len-1, cnt=-1;i>=0;i--){
		if((len-i-1)%3 == 0){
			answer.push_back(0);
			cnt++;
		}
		if(bin[i] == '1'){
			answer[cnt] += arr[(len-i-1)%3];
		}
	}
	for(int i=answer.size()-1;i>=0;i--)
		cout << answer[i];
	cout << endl;
}
