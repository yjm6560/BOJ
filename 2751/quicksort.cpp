#include <iostream>
#include <stdio.h>

using namespace std;

int arr[1000000];

void swap(int x, int y){
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}
void quick(int low, int high)
{
	int quick_low = low;
	int quick_high = high;
	int pivot = low;
	if(low >= high)
		return;
	while(true){
		if(quick_low > quick_high){
			swap(quick_high, pivot);
			break;
		} else if(arr[quick_low] <= arr[pivot]){
			quick_low++;
		} else if(arr[quick_high] >= arr[pivot]){
			quick_high--;
		} else{
			swap(quick_low, quick_high);
		}
	}
	quick(low, quick_high - 1);
	quick(quick_low, high);
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	quick(0, N-1);
	for(int i=0; i<N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
