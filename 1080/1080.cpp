/*
	행렬
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

	int N, M, cnt = 0;
	string A[50], B[50];
	
	cin >> N >> M;

	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<N;i++)
		cin >> B[i];

	for(int i=0;i<N-2;i++){
		for(int j=0;j<M-2;j++){
			if(A[i][j] != B[i][j]){
				cnt++;
				for(int x=0;x<3;x++){
					for(int y=0;y<3;y++){
						A[i+x][j+y] = (A[i+x][j+y]=='0'? '1' : '0');
					}
				}
			}
		}
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(A[i][j] != B[i][j]){
				cout << "-1\n";
				return 0;
			}
	cout << cnt << endl;
}
