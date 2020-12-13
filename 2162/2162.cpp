/*
	선분 그리기
	그래프, 기하
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

bool isCrossed(vector<int> pos1, vector<int> pos2){
	int fn1 = pos1[0]*pos1[3] - pos1[2]*pos1[1] + pos1[2]*pos2[1] - pos2[0]*pos1[3] + pos2[0]*pos1[1] - pos1[0]*pos2[1];
	int fn2 = pos1[0]*pos1[3] - pos1[2]*pos1[1] + pos1[2]*pos2[3] - pos2[2]*pos1[3] + pos2[2]*pos1[1] - pos1[0]*pos2[3];
	return (fn1 * fn2 < 0);
}

int N, group;
vector<int> lines[3000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0;i<N;i++){
		for(int j=0;j<4;j++){
			int	input;
			cin >> input;
			lines[i].push_back(input);
		}
	}
	for(int i=0;i<N;i++){
		group = -1;
		for(auto line_set : answer){
			for(auto check_line : line_set){
				if(isCrossed(check_line, lines[i])){
					if(group > -1){
						// concat line set
						
					} else {
						// make line set
						vector<int> new_line_set;
						new_line_set.push_back(i);
						group = line_set.size();
						line_set.push_back(new_line_set);
					}
					break;
				}
			}
		}
	}
	/*
	for(int i=0;i<N;i++){
		for(auto x : lines[i])
			cout << x << " ";
		cout << endl;
	}
	*/
}
