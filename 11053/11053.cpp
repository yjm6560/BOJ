#include <iostream>

using namespace std;

int arr[1001];
int lcs_arr[1001];
int lcs_max = 1;

int main()
{
	int N;
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> arr[i];
		lcs_arr[i] = 1;
	}
	for(int i=N-1;i>0;i--){
		int max = 0;
		for(int j=i+1; j<=N; j++){
			if(lcs_arr[j] > max && arr[i] < arr[j]){
				max = lcs_arr[j];
			}
		}
		lcs_arr[i] = max + 1;
		if(lcs_arr[i] > lcs_max)
			lcs_max = lcs_arr[i];
	}
	cout << lcs_max << endl;
}
