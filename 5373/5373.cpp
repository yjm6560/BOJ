#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


void move_side(

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, n;
	vector<vector<char>> cube(6, vector<char>(9));
	vector<char> init_color = {'w', 'y', 'r', 'o', 'g', 'b'};
	for(int i=0;i<6;i++)
		for(int j=0;j<9;j++)
			cube[i][j] = init_color[i];
	/*
		0 		- 윗면
		1 ~ 4 	- 옆면
		5 		- 아랫면
		U 윗면		w
		D 아랫면	y
		F 앞면		r	
		B 뒷면		o
		L 왼쪽면	g
		R 오른쪽면	b
	*/
	cin >> T;
	
	while(T--){
		cin >> n;
		string dir;
		while(n--){
			cin >> dir;
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout << cube[0][i*3 + j];
			}
			cout << endl;
		}
	}
	return 0;
}
