#include <iostream>
#include <stdio.h>

using namespace std;

int arr[1000001];
int arr_for_swap[1000001];

void mergesort_part(int low1, int high1, int low2, int high2);

void mergesort_main(int low, int high){
	if(low == high)
		return;
	int mid = (low + high)/2;
	mergesort_main(low, mid);
	mergesort_main(mid+1, high);
	mergesort_part(low, mid, mid+1, high);
}

void mergesort_part(int low1, int high1, int low2, int high2){
	int pat1 = low1;
	int pat2 = low2;
	int pat3 = low1;
	while(true){
		if(pat3 > high2)
			break;
		if(pat1 <= high1 && pat2 <= high2){
			if(arr[pat1] > arr[pat2]){
				arr_for_swap[pat3] = arr[pat2];
				pat2++;
			}else {
				arr_for_swap[pat3] = arr[pat1];
				pat1++;
			}
		}else if(pat1 <= high1){
			arr_for_swap[pat3] = arr[pat1];
			pat1++;
		}else if(pat2 <= high2){
			arr_for_swap[pat3] = arr[pat2];
			pat2++;
		}
		pat3++;
	}
	for(int i=low1; i<=high2; i++)
		arr[i] = arr_for_swap[i];
}
int main()
{
	int N;
	scanf("%d", &N);
	for(int i=1;i<=N;i++){
		scanf("%d ", &arr[i]);
	}
	mergesort_main(1, N);
	for(int i=1;i<=N;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
