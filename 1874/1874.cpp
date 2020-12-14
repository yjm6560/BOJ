/*
	문제 :  
	알고리즘 :  
	문제 설명 : 
			
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	풀이
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, last = 0;
	cin >> N;
	vector<int> arranged(N+1);
	vector<int> myStack;
	vector<char> answer;

	for(int i=0;i<N;i++)
		cin >> arranged[i];
	
	for(int i=1;i<=N;i++){
		myStack.push_back(i);
		answer.push_back('+');
		while(last < N && myStack.back() == arranged[last]){
			answer.push_back('-');
			myStack.pop_back();
			last++;
		}
	}
	
	if(last == N){
		for(auto x : answer)
			cout << x << "\n";
	} else
		cout << "NO\n";

	return 0;
}
