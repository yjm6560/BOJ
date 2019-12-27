#include <iostream>

using namespace std;

int n, k, coin[101], comb[10001], ret_arr[10001];

int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		scanf("%d", &coin[i]);
	for(int i=0;i<=k;i++){
		comb[i] = 0;
	}
	comb[0] = 1;
	for(int i=1;i<=n; i++){
		for(int j=1;j<=k;j++){
			if(j>=coin[i])
				comb[j] += comb[j-coin[i]];
		}
	}
	cout << comb[k] << endl;
}
