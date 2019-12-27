#include <iostream>
#include <queue>

using namespace std;

int count = 0;
queue<pair<int, int>> hanoi_queue;

void hanoi(int from, int mid, int to, int height){
	count++;
	if(height == 1){
		hanoi_queue.push(make_pair(from, to));	
		return;
	}
	hanoi(from, to, mid, height-1);
	hanoi_queue.push(make_pair(from, to));
	hanoi(mid, from, to, height-1);
	return;
}

int main(){
	int n;
	cin >> n;
	hanoi(1,2,3,n);
	printf("%d\n", count);
	while(!hanoi_queue.empty()){
		printf("%d %d\n", hanoi_queue.front().first, hanoi_queue.front().second);
		hanoi_queue.pop();
	}
}
