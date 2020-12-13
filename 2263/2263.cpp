/*
	트리의 순회
	분할 정복
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, root;
vector<int> pos, inOrder, postOrder;
pair<int, int> tree[100001];

void solve(int is, int ie, int ps, int pe){
	if(is == ie || ps == pe)
		return;
	int lie = pos[postOrder[pe]] - 1;
	int ris = pos[postOrder[pe]] + 1;
	int lpe = ps + lie - is;
	int rps = ps + lie - is + 1;
	
	
	if(is <= lie && ps <= lpe){
		tree[postOrder[pe]].first = postOrder[lpe];
//		cout << postOrder[pe] << " left : " << is << " " << lie << " " << ps << " " << lpe << endl;
		solve(is, lie, ps, lpe);
	}
	if(ris <= ie && rps <= pe-1){
		tree[postOrder[pe]].second = postOrder[pe-1];
//		cout << postOrder[pe] << " right : " << ris << " " << ie << " " << rps << " " << pe - 1 <<endl;
		solve(ris, ie, rps, pe - 1);
	}

}

void preOrder(int node){
	if(node == 0)
		return;
	cout << node << " ";
	preOrder(tree[node].first);
	preOrder(tree[node].second);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	memset(tree, 0, sizeof(tree));
	pos.reserve(n+1);
	inOrder.reserve(n+1);
	postOrder.reserve(n+1);

	for(int i=1;i<=n;i++){
		cin >> inOrder[i];
		pos[inOrder[i]] = i;
	}
	for(int i=1;i<=n;i++){
		cin >> postOrder[i];
	}
	root = postOrder[n];
	solve(1, n, 1, n);
//	for(int i=1;i<=n;i++)
//		cout << i << " : " <<  tree[i].first << " " << tree[i].second << endl;
	preOrder(root);
	cout << "\n";
}
