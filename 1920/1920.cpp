#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

#define HASH_SIZE 1000

using namespace std;


int main()
{
	int N, tmp, i, j;
	cin >> N;
	vector< vector<int> > arr;
	arr.reserve(HASH_SIZE);
	for(i=0;i<N;i++){
		scanf("%d", &tmp);
		arr[abs(tmp)%HASH_SIZE].push_back(tmp);
	}
	cin >> N;
	for(i=0; i<N; i++){
		scanf("%d", &tmp);
		for(j=0;j<arr[abs(tmp)%HASH_SIZE].size();j++){
			if(tmp == arr[abs(tmp)%HASH_SIZE][j]){
				printf("1\n");
				break;
			}
		}
		if(j == arr[abs(tmp)%HASH_SIZE].size()){
			printf("0\n");
		}
	}
}
