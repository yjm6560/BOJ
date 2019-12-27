#include <iostream>
#include <string>
#include <vector>

using namespace std;
class node{
	public:
	int left, right, val;
	node(){left=right=val=-1;}
};
class maxHeap{
	vector<node> maxheap;
	public:
	maxHeap(){}
	void push(int val){
		maxheap.push_back(val);
		
};
int main()
{
	int n, cmd;
	vector<int> maxHeap;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> cmd;
		if(cmd==0){
			if(maxHeap.empty()){
				cout << 0 << endl;
			}
			else{
				cout << maxHeap.back() << endl;
				maxHeap.pop_back();
			}
			
		}
		else
		{
			vector<int>::iterator it;
			if(maxHeap.empty()){
				maxHeap.push_back(cmd);
				continue;
			}
			for(it=maxHeap.begin();it<maxHeap.end();it++){
				if(cmd < *it){
					maxHeap.insert(it, 1, cmd);
					break;
				}
			}
			if(it == maxHeap.end()){
				maxHeap.push_back(cmd);
			}
		}
	}
}
