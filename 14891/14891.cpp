#include <iostream>
#include <vector>
#include <algorithm>

#define N_GEAR 4
#define N_WHEEL 8

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int K, gear_idx, direction, answer = 0;
	vector<vector<bool>> gear(N_GEAR, vector<bool>(N_WHEEL, false));
	string input;
	for(int i=0;i<N_GEAR;i++){
		cin >> input;
		for(int j=0;j<N_WHEEL;j++){
			gear[i][j] = input[j]=='0'? 0 : 1;
		}
	}

	cin >> K;
	while(K--){
		cin >> gear_idx >> direction;
		gear_idx--;
		cout << gear_idx << " " << direction << endl;
		rotate(gear[gear_idx].begin(), gear[gear_idx].begin() + (N_WHEEL - direction)%N_WHEEL, gear[gear_idx].end());
		int left_direction = -direction;
		int right_direction = -direction;
		for(int i=gear_idx-1;i>0;i--, left_direction *= -1){
			if(gear[i+1][6] != gear[i][2]){
				rotate(gear[i].begin(), gear[i].begin() + (N_WHEEL - left_direction)%N_WHEEL, gear[i].end());
			} else {
				break;
			}
		}
		
		for(int i=gear_idx;i<N_GEAR-1;i++, right_direction *= -1){
			cout << i << endl;
			if(gear[i+1][6] != gear[i][2]){
				rotate(gear[i+1].begin(), gear[i+1].begin() + (N_WHEEL - right_direction)%N_WHEEL, gear[i+1].end());
			} else {
				break;
			}
		}
		
		for(int i=0;i<N_GEAR;i++){
			for(auto x : gear[i])
				cout << x;
			cout << endl;
		}
		cout << endl;
	}


	return 0;
}
