#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;

	cin >> N;
	vector<int> segTree(2*N);

	for(int i=N;i<2*N;i++)
		cin >> segTree[i];
	
	for(int i=2*N-1;i>=1;i--)
		segTree[i/2] += segTree[i];
	
	int M, s, e;
	cin >> M;
	while(M--){
		cin >> s >> e;
		cout << s << " ~ " << e << " : ";
		s += N;
		e += N;
		int answer = 0;
		while(s<=e){
			if(s%2 == 1) answer += segTree[s++];
			if(e%2 == 0) answer += segTree[e--];
			s /= 2; e /=2;
		}
		cout << answer << endl;
	}
	

	return 0;
}
