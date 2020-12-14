/*
	시간 초과
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_EMPLOYEE 500000

using namespace std;

vector<int> emp(MAX_EMPLOYEE+1, 0);
vector<int> sal(MAX_EMPLOYEE+1, 0);
vector<int> gap(MAX_EMPLOYEE+1, 0);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, a, x;
	char cmd;
	bool updated = false;
	cin >> N >> M;

	cin >> sal[1];

	for(int i=2;i<=N;i++)
		cin >> sal[i] >> emp[i];
	
	for(int i=0;i<M;i++){
		cin >> cmd;
		if(cmd == 'p'){
			cin >> a >> x;
			gap[a] += x;
		} else {
			cin >> a;
			int answer = sal[a];
			int parent = emp[a];
			while(parent){
				answer += gap[parent];
				parent = emp[parent];
			}
			cout << answer << "\n";
		}
	}
	
	return 0;
}
