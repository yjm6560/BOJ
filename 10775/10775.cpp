#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int G, P, answer = 0;
	cin >> G >> P;
	vector<int > gi(P,0);
	vector<bool>docking(P,0);

	for(int i=0;i<P;i++){
		cin >> gi[i];
		int idx = gi[i];
		while(idx) {
			if(!docking[idx]) {
				docking[idx] = true;
				answer++;
				break;
			}
			idx--;
		}
		if(idx == 0) {
			cout<<answer<<"\n";
			return 0;
		}
	}
	return 0;
}
