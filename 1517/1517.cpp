/*
	버블 소트
	정렬, 분할 정복
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N;
long long cnt=0;
vector<int> num, temp;

void merge2(int fs, int fe, int ss, int se){
	int fc = fs;
	int sc = ss;
	int nc = fs;
	while(fc<=fe && sc<=se){
		if(num[fc] <= num[sc]){
			temp[nc] = num[fc];
			fc++;
		} else {
			temp[nc] = num[sc];
			sc++;
			cnt += (fe-fc)+1;
		}
		nc++;
	}
	if(fc <= fe){
		for(int i=fc;i<=fe;i++,nc++)
			temp[nc] = num[i];
	} else {
		for(int i=sc;i<=se;i++,nc++)
			temp[nc] = num[i];
	}
	for(int i=fs;i<=se;i++)
		num[i] = temp[i];
}

void merge1(int s, int e){
	if(s==e)
		return;
	int mid = (s+e)/2;
	merge1(s, mid);
	merge1(mid+1, e);

	merge2(s, mid, mid+1, e);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	num.reserve(N);
	temp.reserve(N);

	for(int i=0;i<N;i++)
		cin >> num[i];
	merge1(0, N-1);
	cout << cnt << endl;
}
