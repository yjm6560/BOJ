/*
	골드바흐의 추측
	수학
*/
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	bool isPrime[1000001];
	vector<int> primes;
	memset(isPrime, 0, sizeof(isPrime));
	isPrime[1] = true;
	for(int i=2;i<=1000000;i++){
		if(isPrime[i])
			continue;
		for(int j=i+i;j<=1000000;j+=i)
			isPrime[j] = true;
	}
	for(int i=2;i<=1000000;i++)
		if(!isPrime[i])
			primes.push_back(i);
	
	while(true){
		cin >> n;
		if(!n)
			break;
		x = y = 0;
		for(int i=3;i<n;i+=2){
			if(!isPrime[i] && !isPrime[n-i]){
				x = i;
				y = n-i;
				break;
			}
		}
		if(x || y)
			cout << n << " = " << x << " + " << y << "\n";
		else
			cout << "Goldbach's conjecture is wrong.\n";
	}
}
