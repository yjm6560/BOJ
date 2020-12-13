/*
	-2진수
	수학
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long num;
	vector<int> answer;
	cin >> num;
	do {
		if(num%2)
			answer.push_back(1);
		else
			answer.push_back(0);
		num = (num>0? num/2 : (num-1)/2)*-1;
	} while(num != 0);
	for(auto itr = answer.end()-1;itr >= answer.begin();itr--)
		cout << *itr;
	cout << endl;
}
