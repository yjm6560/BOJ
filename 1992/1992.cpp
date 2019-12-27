#include <iostream>

using namespace std;

int arr[65][65];
int N;

void quadTree(int x, int y, int phase){
	int standard = arr[x][y];
	if(phase == 1){
		printf("%d",standard);
		return;
	}
	for(int i=x;i<x+phase;i++){
		for(int j=y;j<y+phase;j++){
			if(arr[i][j] != standard){
				printf("(");
				int nextPhase = phase/2;
				quadTree(x, y, nextPhase);
				quadTree(x, y+nextPhase, nextPhase);
				quadTree(x+nextPhase, y, nextPhase);
				quadTree(x+nextPhase, y+nextPhase, nextPhase);
				printf(")");
				return;
			}
		}
	}
	printf("%d", arr[x][y]);
}

int main(){
	cin >> N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf("%1d", &arr[i][j]);
	quadTree(1, 1, N);
}
