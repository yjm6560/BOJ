#include <iostream>
#include <vector>
#include <algorithm>

#define MIN 0
#define MAX 999999999

using namespace std;

typedef long long LL;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int segN, N, M, a, b;
	cin >> N >> M;
	//1. N보다 큰 2의 제곱수 찾기
	for(segN=1;segN<N;segN*=2);

	//2. segmentTree vector 선언 후 입력 받기
	vector<pair<LL, LL>> segmentTree(segN*2, {MAX, MIN});
	for(int i=segN;i<segN+N;i++){
		cin >> segmentTree[i].first;
		segmentTree[i].second = segmentTree[i].first;
	}
	
	//3. segmentTree 생성
	for(int i=segN*2-1;i>1;i--){
		segmentTree[i/2].first = min(segmentTree[i/2].first, segmentTree[i].first);
		segmentTree[i/2].second = max(segmentTree[i/2].second, segmentTree[i].second);
	}
	
	//구간 최소값, 최대값 구하기
	while(M--){
		cin >> a >> b;
		a += segN - 1;
		b += segN - 1;
		LL minAnswer = MAX;
		LL maxAnswer = MIN;
		while(a<=b){
			if(a%2 == 1){
				minAnswer = min(minAnswer, segmentTree[a].first);
				maxAnswer = max(maxAnswer, segmentTree[a].second);
				a++;
			}
			if(b%2 == 0){
				minAnswer = min(minAnswer, segmentTree[b].first);
				maxAnswer = max(maxAnswer, segmentTree[b].second);
				b--;
			}
			a /= 2;
			b /= 2;
		}
		cout << minAnswer << " " << maxAnswer << "\n";
	}

	return 0;
}
