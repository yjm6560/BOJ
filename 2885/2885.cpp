/*
	초콜릿 식사
	그리디
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, x, val, cnt=0;
bool check = false;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;

	for(x = 1<<30; K>0; x=x>>1){
		if(x <= K){
			if(!check){
				if(x == K){
					val = x;
					break;
				}
				val = x<<1;
				check = true;
			}
			K -= x;
		}
		if(check)
			cnt++;
	}
	cout << val << " " << cnt << endl;
}
