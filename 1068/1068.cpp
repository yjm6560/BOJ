#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class node{
	public:
	vector<int> child;
	node(){}
};
node *tree = new node[51];
int n, deleteNode, root;
int leafCount = 0;

void search(int num)
{
	if(tree[num].child.size() == 0){
		leafCount++;
		return;
	}
	for(int i=0;i<tree[num].child.size();i++){
		if(tree[num].child[i] == deleteNode){
			if(tree[num].child.size() == 1&& num != root){
				leafCount++;
			}
			continue;
		}
		search(tree[num].child[i]);
	}
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp == -1){
			root = i;
			continue;
		}
	
		tree[tmp].child.push_back(i);
	}
	cin >> deleteNode;
	if(deleteNode == root){
		printf("0\n");
		return 0;
	}
	search(root);
	printf("%d\n", leafCount);
}
