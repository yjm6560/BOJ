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
	vector<vector<bool>> gear(N_GEAR+1, vector<bool>(N_WHEEL, false));
	string input;
	for(int i=1;i<=N_GEAR;i++){
		cin >> input;
		for(int j=0;j<N_WHEEL;j++){
			gear[i][j] = input[j]=='0'? 0 : 1;
		}
	}

	cin >> K;
	vector<bool> diff(5, false);

	while(K--){
		cin >> gear_idx >> direction;
		
		fill(diff.begin(), diff.end(), false);
	
		int left_direction = -direction;
		int right_direction = -direction;

		for(int i=gear_idx+1;i<=N_GEAR;i++){
			//left check
			diff[i] = gear[i][6] != gear[i-1][2];
		}

		for(int i=gear_idx-1;i>0;i--){
			//right check
			diff[i] = gear[i][2] != gear[i+1][6];
		}
	
		rotate(gear[gear_idx].begin(), (direction==1? gear[gear_idx].end() - 1 : gear[gear_idx].begin() + 1), gear[gear_idx].end());

		for(int i=gear_idx+1;i<=N_GEAR && diff[i];i++, left_direction *= -1)
			rotate(gear[i].begin(), (left_direction==1? gear[i].end() - 1 : gear[i].begin() + 1), gear[i].end());

		for(int i=gear_idx-1;i>0 && diff[i];i--, right_direction *= -1)
			rotate(gear[i].begin(), (right_direction==1? gear[i].end() - 1 : gear[i].begin() + 1), gear[i].end());
	}
	vector<int> squared = {0, 1, 2, 4, 8};
	for(int i=1;i<=N_GEAR;i++){
		if(gear[i][0])
			answer += squared[i];
	}
	cout << answer << "\n";


	return 0;
}
