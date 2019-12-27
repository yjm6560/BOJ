#include <iostream>

using namespace std;

int arr[1001];
int lcs_arr[1001];
int lcs_max = 1;

int main()
{
	int N, A, maxA = 0;
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A;
		cin >> arr[A];
		lcs_arr[A] = 1;
		if(arr[A] > maxA) maxA = arr[A];
	}
	for(int i=maxA-1;i>0;i--){
		int max = 0;
		for(int j=i+1; j<=maxA; j++){
			if(arr[i] > 0 && lcs_arr[j] > max && arr[i] < arr[j]){
				max = lcs_arr[j];
			}
		}
		lcs_arr[i] = max + 1;
		if(lcs_arr[i] > lcs_max)
			lcs_max = lcs_arr[i];
	}
	cout << N-lcs_max << endl;
}
