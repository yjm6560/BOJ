/*
	8진수 2진수
	수학
*/
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string aug, bin;
	int arr[3] = {4, 2, 1};
	bool check = false;
	cin >> aug;
	for(int i=0;aug[i];i++){
		int num = aug[i] - '0';
		for(int j=0;j<3;j++){
			if(num/arr[j]){
				cout << 1;
				num -= arr[j];
				check = true;
			}
			else if(check)
				cout << 0;
		}
	}
	if(!check)
		cout << 0;
	cout << endl;
}
