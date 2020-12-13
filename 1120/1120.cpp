/*
	문자열
	그리디
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string X, Y;
	int ret = 987654321;
	cin >> X >> Y;
	
	for(int i=0;i<=Y.length()-X.length();i++){
		int cnt = 0;
		for(int j=0;j<X.length();j++){
			if(Y[i+j] != X[j])
				cnt++;
		}
		ret = min(ret, cnt);
	}
	cout << ret << endl;
}
