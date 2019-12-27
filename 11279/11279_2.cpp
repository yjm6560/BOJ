#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class maxHeap{
	vector<int> heap;
	public:
	maxHeap(){heap.reserve(1000001); heap.push_back(-1);}
	void push(int val){
		heap.push_back(val);
		int current = heap.size() - 1;
		while(1){
			if(current == 1 || heap[current] < heap[current/2]){
				break;
			}
			else {
				int tmp = heap[current];
				heap[current] = heap[current/2];
				heap[current/2] = tmp;
				current /= 2;
			}
		}
	}
	int pop(){
		int current = 1;
		int max = heap[current];
		if(heap.size() == 1)
			return 0;
		heap[current] = heap[heap.size() - 1];
		heap.pop_back();
		while(1){
			if(2*current > heap.size() - 1){
				break;
			}
			else if(heap[current] < heap[current*2]){
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
			}
		}
		return max;
	}
};
int main()
{
	maxHeap heap;
	int n, val;
	cin >> n;
	while(n--){
		scanf("%d", &val);
		if(val == 0){
			cout << heap.pop() << endl;
		}
		else{
			heap.push(val);
		}
	}
}
