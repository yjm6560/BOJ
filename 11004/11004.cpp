/*
	K번째 수
	정렬
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long N, K, input;
	vector<long long> num;

	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> input;
		num.push_back(input);
	}

	sort(num.begin(), num.end());

	cout << num[K-1] << endl;
}
