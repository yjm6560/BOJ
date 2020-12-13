/*
2 x n tiling
   */

#include <iostream>
#include <vector>

using namespace std;

#define MOD 10007

int main()
{
	int n;
	int tile[1000];
	cin >> n;
	
	tile[0] = 1;
	tile[1] = 2;
	for(int i=2;i<n;i++){
		tile[i] = (tile[i-1] + tile[i-2])%MOD;
	}
	cout << tile[n-1] << endl;
}
