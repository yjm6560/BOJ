#include <iostream>

using namespace std;

int main()
{
	int T;
	long long arr[101] = { 0, 1, 1, 1, 2, 2 };

	scanf("%d", &T);

	for(int i=0;i<T;i++){
		int N;
		scanf("%d", &N);
		for(int j=6;j<=N;j++){
			arr[j] = arr[j-1] + arr[j-5];
		}
		printf("%lld\n", arr[N]);
	}	
}
