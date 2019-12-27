#include <iostream>

using namespace std;

int main()
{
	int N, M, arr[100], max = 0;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			int ij = arr[i]+arr[j];
			for(int k=j+1;k<N;k++){
				int tmp = ij+arr[k];
				if(tmp <= M && tmp > max)
					max = tmp;
			}
		}
	}
	cout << max << endl;
}
