#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

typedef long long LL;

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int segN, N, M, K;
	LL a, b, c;
	cin >> N >> M >> K;
	
	//1. N이상의 2의 제곱수 찾기 -> segN
	for(segN=1;N>segN;segN*=2);

	//2. segmentTree 공간 확보
	vector<LL> segmentTree(segN*2, 0);
	
	//3. 인풋 받기
	for(int i=segN;i<segN+N;i++)
		cin >> segmentTree[i];
	//4. segmentTree 생성
	for(int pat=segN*2-1;pat>1;pat--)
		segmentTree[pat/2] += segmentTree[pat];
	
	//5. 명령어 수행
	for(int i=0;i<M+K;i++){
		cin >> a >> b >> c;
		if(a == 1){
			//5-1. 숫자 변경
			b += segN - 1;
			LL gap = c - segmentTree[b];
			while(b>0){
				segmentTree[b] += gap;
				b /= 2;
			}
		} else if(a == 2) {
			//5-2. 구간합 출력
			b += segN - 1, c += segN - 1;
			LL answer = 0;
			while(b<=c){
				if(b%2 == 1) answer += segmentTree[b++];
				if(c%2 == 0) answer += segmentTree[c--];
				b /= 2;
				c /= 2;
			}
			cout << answer << "\n";
		}
	}

	return 0;
}
