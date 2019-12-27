#include <iostream>

using namespace std;

bool arr[2200][2200];
int N;
void funct(int x, int y, int phase){
	if(x > N || y > N) return;
	if(phase == 1) {
		arr[x][y] = true;
		return;
	}
	int nextPhase = phase/3;
        funct(x, y, nextPhase);
        funct(x+nextPhase, y, nextPhase);
        funct(x+2*nextPhase, y, nextPhase);
        funct(x, y+nextPhase, nextPhase);
        funct(x+2*nextPhase, y+nextPhase, nextPhase);
        funct(x, y+2*nextPhase, nextPhase);
        funct(x+nextPhase, y+2*nextPhase, nextPhase);
        funct(x+2*nextPhase, y+2*nextPhase, nextPhase);
        return;
}

int main(){
	cin >> N;
	funct(1, 1, N);
	for(int i=1;i<=N;i++){
        	for(int j=1;j<=N;j++){
	        	if(arr[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
