/*
	나이순 정렬
	정렬
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, age;
	string name;
	vector<pair<int, pair<int, string>>> member;

	cin >> N;
	for(int i=0;i<N;i++){
		cin >> age >> name;
		member.push_back({age, {i, name}});
	}

	sort(member.begin(), member.end());

	for(auto m : member)
		cout << m.first << " " << m.second.second << "\n";

}
