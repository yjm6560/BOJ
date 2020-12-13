/*
   N-Queen
   dp
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_VAL 99999

int N, cnt = 0;
bool col[MAX_VAL], diag1[MAX_VAL*2], diag2[MAX_VAL*2];
void nq(int x, int y){
	if(x == N){
		cnt++;
		return;
	}
	for(int i=0;i<N;i++){
		if(col[i] && diag1[x+i] && diag2[N-x+i-1]){
			col[i] = diag1[x+i] = diag2[N-x+i-1] = false;
			nq(x+1,i);
			col[i] = diag1[x+i] = diag2[N-x+i-1] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i=0;i<N;i++) col[i] = true;
	for(int i=0;i<2*N;i++) diag1[i] = diag2[i] = true;
	
	nq(0,0);
	cout << cnt << endl;
}

