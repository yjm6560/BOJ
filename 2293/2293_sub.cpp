#include <iostream>

using namespace std;

int n, k, coin[101], comb[101][10001];

int coin_dp(int pos, int capacity){
	if(pos == n+1)
		if(capacity == 0) return 1;
		else return 0;

	if(comb[pos][capacity] != -1) return comb[pos][capacity];
	int ret = 0;
	for(int i=0;i<=capacity;i+=coin[pos]){
		ret += coin_dp(pos+1, capacity - i);
	}
	return comb[pos][capacity] = ret;
}
int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		scanf("%d", &coin[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			comb[i][j] = -1;
		}
	}
	cout << coin_dp(1,k) << endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++)
			cout << comb[i][j] << " ";
		cout << endl;
	}
}
