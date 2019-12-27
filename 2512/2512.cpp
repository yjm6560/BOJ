#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

long N, totalBudget, b_max = 0;long limitBudget = 0;
long budget[10000];
long tBudget[100001] ={0};

long maxBudget(long limit){
	long max = 0;
	for(long i=0;i<N;i++)
		max += (budget[i] > limit ? limit : budget[i]);
	return max > totalBudget ? 0 : max;
}

void binarySearch(long beg, long end){
	long limit = (beg + end)/2;
	if(tBudget[limit] > 0)
		return;
	tBudget[limit] = maxBudget(limit);
	if(tBudget[limit] > b_max){
		limitBudget = limit;
		b_max = tBudget[limit];
		binarySearch(limit, end);
	}
	else{
		binarySearch(beg, limit);
	}
	
}
int main()
{
	scanf("%ld", &N);
	long maxOneBudget = 0;
	long maxOneBudgetIndex;
	for(long i=0;i< N;i++){
		scanf("%ld", &budget[i]);
		if(budget[i] > maxOneBudget){
			maxOneBudget = budget[i];
			maxOneBudgetIndex = i;
		}
	}
	scanf("%ld", &totalBudget);
	tBudget[1] = N;
	tBudget[100000] = maxBudget(100000);
	b_max = N;
	limitBudget = 1;
	binarySearch(1, maxOneBudget+1);
	printf("%ld\n", limitBudget);
}
