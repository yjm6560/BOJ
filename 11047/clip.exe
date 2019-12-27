#include <iostream>

using namespace std;

long long N, K, coins[10], count = 0;

long long comb_coin(long long order, long long budget){
	if(budget == 0)
		return 0;
	for(long long i = budget/coins[order]; i >= 0; i--){
		long long ret = comb_coin(order-1, budget - i*coins[order]);
		if(ret == 0){
			count += i;
			return 0;
		}
	}
	return -1;
}

int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> coins[i];
	comb_coin(N-1, K);
	cout << count << endl;
}
