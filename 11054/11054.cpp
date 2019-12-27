#include <iostream>

using namespace std;

int arr[1001];
int lcs_arr1[1001];
int lcs_arr2[1001];
int N, lcs_max = 1;

void left(int idx){
	int max = 0;
	for(int i = idx-1; i>0; i--){
		if(lcs_arr1[i] == 0)
			left(i);
		if(lcs_arr1[i] > max && arr[idx] > arr[i])
			max = lcs_arr1[i];
	}
	lcs_arr1[idx] = max + 1;
}
void right(int idx){
	int max = 0;
	for(int i = idx+1; i<=N; i++){
		if(lcs_arr2[i] == 0)
			right(i);
		if(lcs_arr2[i] > max && arr[idx] > arr[i])
			max = lcs_arr2[i];
	}
	lcs_arr2[idx] = max + 1;
}
int main()
{
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> arr[i];
		lcs_arr1[i] = 0;
		lcs_arr2[i] = 0;
	}
	lcs_arr1[1] = lcs_arr2[N] = 1;
	left(N);
	right(1);
	for(int i=1;i<=N;i++){
		if(lcs_arr1[i]+lcs_arr2[i] > lcs_max)
			lcs_max = lcs_arr1[i]+lcs_arr2[i];
	}
	cout << lcs_max-1 << endl;
}
