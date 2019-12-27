#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> heap;

void push(int val){
	heap.push_back(val);
	int current = heap.size() - 1;
	while(current != 1 && heap[current] >= heap[current/2]){
		int tmp = heap[current];
		heap[current] = heap[current/2];
		heap[current/2] = tmp;
		current /= 2;
	}
}
int pop(){
	int current = 1;
	int max = heap[current];
	if(heap.size() == 1)
		return 0;
	heap[current] = heap[heap.size() - 1];
	heap.pop_back();
	while(2*current <= heap.size() - 1){
		if(heap[current] < heap[current*2]){
			int tmp = heap[current];
			heap[current] = heap[current*2];
			heap[current*2] = tmp;
			current = current * 2;
		}
		else if(2*current + 1 > heap.size() - 1){
			break;
		}
		else if(heap[current] < heap[current*2 + 1]){
			int tmp = heap[current];
			heap[current] = heap[current*2 + 1];
			heap[current*2 + 1] = tmp;
			current = current*2 + 1;
		}
	}
	return max;
}
int main()
{
	heap.push_back(-1);
	int n, val;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &val);
		if(val == 0){
			printf("%d\n",pop());
		}
		else{
			push(val);
		}
	}
}
