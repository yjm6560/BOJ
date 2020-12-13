/*
	멀티탭 스케줄링
	그리디
	문제 설명 :
	N개의 플러그가 있는 멀티탭에에 임의의 플러그를 K 번 삽입하려 할 떄 멀티탭에서 플러그를 빼야하는 최소값을 출력한다.
	N, K가 순서대로 주어지고 다음 줄부터 K줄 동안 플러그 꼽는 순서가 주어진다.
	N, K는 1 이상 100 이하
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

/*
	고려할 경우의 수
	1. i번 플러그가 이미 꽂혀 있는 경우
	2. i번 플러그는 꽂혀 있지 않지만 콘센트가 남은 경우
	3. i번 플러그도 안 꽂혀 있고 콘센트도 꽉 차 있는 경우

	1번은 그냥 내비두면 된다. 
	2번은 꽂으면 된다.
	3번은 멀티탭에 꽂혀 있는 플러그들 중에서 가장 늦게 사용할 플러그를 찾아 교체한다. 이때 카운트 값이 증가한다.

	plug를 {플러그 번호, 다음에 나오는 가장 가까운 플러그 순번} 쌍으로 지정해놓고
	멀티탭에는 몇번째 순서의 플러그를 사용했는지를 기록한다.
	그렇게 계속 찾아나가면 된다.
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K, cnt = 0;
	const int INF = 987654321;

	cin >> N >> K;

	vector<pair<int, int>> plug(K+1);
	vector<int> multiTab;

	for(int i=1;i<=K;i++)
		cin >> plug[i].first;

	for(int i=1;i<=K;i++){
		bool check = false;
		for(int j=i+1;j<=K;j++){
			if(plug[i].first == plug[j].first){
				plug[i].second = j;
				check = true;
				break;
			}
		}
		if(!check)
			plug[i].second = INF;
	}
	

	for(int i=1;i<=K;i++){
		int changed = -1;
		bool check = false;
		for(int j=0;j<multiTab.size();j++){
			if(plug[multiTab[j]].first == plug[i].first){
				multiTab[j] = i;
				check = true;
				break;
			}
			if(changed == -1 || plug[multiTab[changed]].second < plug[multiTab[j]].second)
				changed = j;
		}
		if(check)
			continue;
		
		if(multiTab.size() < N){
			multiTab.push_back(i);
		} else {
			multiTab[changed] = i;
			cnt++;
		}
	}
	cout << cnt << endl;
}
