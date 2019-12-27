#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class node{
	public:
	char data;
	vector<int> child;
};

struct node *tree = new node[26];

void preorder(int nowNode){
	if(nowNode == -19)
		return;
	printf("%c", nowNode + 'A');
	preorder(tree[nowNode].child[0]);
	preorder(tree[nowNode].child[1]);
}

void midorder(int nowNode){
	if(nowNode == -19)
		return;
	midorder(tree[nowNode].child[0]);
	printf("%c", nowNode + 'A');
	midorder(tree[nowNode].child[1]);
}

void behindorder(int nowNode){
	if(nowNode == -19)
		return;
	behindorder(tree[nowNode].child[0]);
	behindorder(tree[nowNode].child[1]);
	printf("%c", nowNode + 'A');
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		char x, y, z;
		cin >> x >> y >> z;
		tree[x - 'A'].child.push_back(y - 'A');
		tree[x - 'A'].child.push_back(z - 'A'); 
	}
	preorder(0);
	printf("\n");
	midorder(0);
	printf("\n");
	behindorder(0);
	printf("\n");
}
