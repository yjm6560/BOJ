/*
	수 묶기
	그리디
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

	int N, input, answer = 0;
	vector<int> minus;
	vector<int> plus;
	
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> input;
		if(input > 1)
			plus.push_back(input);
		else if(input == 1)
			answer++;
		else
			minus.push_back(input);
	}

	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end());
	
	int nMinus = minus.size();
	int nPlus = plus.size();

	for(int i=0;i<nMinus-1;i+=2){
		answer += (minus[i] * minus[i+1]);
	}
	for(int i=nPlus-1;i>0;i-=2){
		answer += (plus[i] * plus[i-1]);
	}
	if(nMinus%2 == 1)
		answer += minus[nMinus-1];
	if(nPlus%2 == 1)
		answer += plus[0];
	cout << answer << endl;
			
}
