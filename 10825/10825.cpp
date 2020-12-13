/*
	국영수
	정렬
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct s {
	int kor, eng, mat;
	string name;
} s;

bool compare(s x, s y){
	if(x.kor > y.kor)
		return true;
	if(x.kor == y.kor){
		if(x.eng < y.eng)
			return true;
		if(x.eng == y.eng){
			if(x.mat > y.mat)
				return true;
			if(x.mat == y.mat){
				if(x.name < y.name)
					return true;
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	vector<s> mem;

	cin >> N;
	for(int i=0;i<N;i++){
		s input;
		cin >> input.name >> input.kor >> input.eng >> input.mat;
		mem.push_back(input);
	}

	sort(mem.begin(), mem.end(), compare);

   for(auto x : mem)
		cout << x.name << "\n";

}
