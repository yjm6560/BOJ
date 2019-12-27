#include <iostream>

using namespace std;

int main()
{
	int N, tmp, arr[10001] = {0};
	cin >> N;
	for(int i=0;i<N;i++){
		scanf("%d",&tmp);
		arr[tmp]++;
	}
	for(int i=1;i<=10000;i++){
		while(arr[i] > 0){
			printf("%d\n", i);
			arr[i]--;
		}
	}
}
