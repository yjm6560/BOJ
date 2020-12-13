/*
	카드
	정렬
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long N, input, answer, max_val=1, cnt=0;
	vector<long long> card;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> input;
		card.push_back(input);
	}
	
	sort(card.begin(), card.end());
	
	answer = card[0];
	cnt = 1;
	for(int i=1;i<card.size();i++){
		if(card[i] == card[i-1])
			cnt++;
		else
			cnt = 1;
		if(max_val < cnt){
			max_val = cnt;
			answer = card[i];
		}
	}
	cout << answer << endl;
}
