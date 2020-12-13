/*
   n-queen
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> odd_ret, even_ret;
	for(int i=1;i<=N;i+=2){
		odd_ret.push_back(i);
	}
	for(int i=2;i<=N;i+=2){
		even_ret.push_back(i);
	}
	if(N%6 == 2){
		odd_ret[0] = 3;
		odd_ret[1] = 1;
		odd_ret.push_back(5);
		for(auto x : even_ret)
			cout << x << "\n";
		cout << "3\n1\n";
		for(int i=3;i<odd_ret.size();i++)
			cout << odd_ret[i] << "\n";

	} else if(N%6 == 3){
		even_ret.push_back(2);
		odd_ret.push_back(1);
		odd_ret.push_back(3);
		for(int i=1;i<even_ret.size();i++)
			cout << even_ret[i] << "\n";
		for(int i=2;i<odd_ret.size();i++)
			cout << odd_ret[i] << "\n";
	} else {
		for(auto x : even_ret)
			cout << x << "\n";
		for(auto x : odd_ret)
			cout << x << "\n";
	}
}
