/*
	주사위
	그리디
	난이도 1.5
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits.h>

using namespace std;



long long solve(long long N, vector<long long> dice){
	vector<long long> maxDice(7);
	maxDice[0] = maxDice[4] = maxDice[6] = 0;
	maxDice[1] = *min_element(dice.begin(), dice.end());
	maxDice[2] = maxDice[3] = 99999999987654321;
	for(int i=0;i<6;i++){
		for(int j=i+1;j<6;j++){
			if((i+j)%5 == 0)
				continue;
			maxDice[2] = min(maxDice[2], dice[i]+dice[j]);
		}
	}
	for(int i=1;i<5;i++){
		for(int j=i+1;j<5;j++){
			if((i+j)%5 == 0)
				continue;
			maxDice[3] = min(maxDice[3], min(dice[5]+dice[i]+dice[j], dice[0]+dice[i]+dice[j]));
		}
	}
	maxDice[5] = accumulate(dice.begin(), dice.end(), 0) - *max_element(dice.begin(), dice.end());
	
	if(N==1)
		return maxDice[5];
	if(N==2)
		return 4*(maxDice[2]+maxDice[3]);
	return (5*N*N-16*N+12)*maxDice[1] + (2*N - 3)*4*maxDice[2] + 4*maxDice[3];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long N;
	vector<long long> dice(6);
	cin >> N;
	for(int i=0;i<6;i++)
		cin >> dice[i];
	cout << solve(N, dice) << endl;
}
