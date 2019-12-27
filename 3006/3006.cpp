#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
#define PB push_back

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, input;
	vi arr;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> input;
		arr.PB(input);
	}

	for(int i=0;i<N;i++){
		int cnt = 0;
		if(i%2 == 0){
			//odd num
			int index = 1 + i/2;
			for(int j=index-1;j<N-index+1;j++){
				if(arr[j] == index){
					for(int k=j;k>=index;k--){
						swap(arr[k], arr[k-1]);
						cnt++;
					}
					break;
				}
			}
		} else {
			//even num
			int index = 1 + i/2;
			for(int j=index;j<N-index+1;j++){
				if(arr[j] == N - index + 1){
					for(int k=j;k<N-index;k++){
						swap(arr[k], arr[k+1]);
						cnt++;
					}
					break;
				}
			}
		}
		cout << cnt << "\n";
	}
}
