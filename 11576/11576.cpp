/*
	Base Conversion
	수학
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, B, m, input, digit = 1, decimal = 0;
	vector<int> num_o, answer;

	cin >> A >> B >> m;
	for(int i=0;i<m;i++){
		cin >> input;
		num_o.push_back(input);
	}
	for(auto itr=num_o.end()-1;itr>=num_o.begin();itr--){
		decimal += (*itr) * digit;
		digit *= A;
	}
	while(decimal){
		answer.push_back(decimal%B);
		decimal /= B;
	}
	digit = 1;
	for(auto itr=answer.end()-1;itr>=answer.begin();itr--){
		cout << *itr << " ";
		digit *= B;
	}
}
