#include <iostream>

using namespace std;

int arr[2200][2200];
int N;
int pcount = 0;
int zcount = 0;
int mcount = 0;

void funct(int x, int y, int phase){
    int standard = arr[x][y];
    for(int i=x;i<x+phase;i++){
        for(int j=y;j<y+phase;j++){
            if(arr[i][j] != standard){
                int nextPhase = phase/3;
                funct(x, y, nextPhase);
                funct(x+nextPhase, y, nextPhase);
                funct(x+2*nextPhase, y, nextPhase);
                funct(x, y+nextPhase, nextPhase);
                funct(x+nextPhase, y+nextPhase, nextPhase);
                funct(x+2*nextPhase, y+nextPhase, nextPhase);
                funct(x, y+2*nextPhase, nextPhase);
                funct(x+nextPhase, y+2*nextPhase, nextPhase);
                funct(x+2*nextPhase, y+2*nextPhase, nextPhase);
                return;
            }
        }
    }
    if(standard == -1)mcount++;
    else if(standard == 0)zcount++;
    else if(standard == 1)pcount++;
    return;
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            scanf("%d", &arr[i][j]);
    funct(1, 1, N);
    printf("%d\n%d\n%d\n", mcount, zcount, pcount);
}
