#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define REP(i, a, b) for(int i=a; i<b;i++)

int main()
{
	int payment;
	int tot_count = 0;
	cin >> payment;
	payment = 1000 - payment;
	vi coins = {500, 100, 50, 10, 5, 1};
	REP(i, 0, coins.size()){
		tot_count += payment / coins[i];
		payment %= coins[i];
	}
	cout << tot_count << endl;
}
