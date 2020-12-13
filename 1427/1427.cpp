/*
	sort
	소트인사이드
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	/*
	string num;
	vector<int> sorted_num;
	cin >> num;

	for(int i=0;i<num.length();i++){
		sorted_num.push_back((int)(num[i]) - '0');
	}

	sort(sorted_num.begin(), sorted_num.end(), greater<int>());

	for(auto n : sorted_num)
		cout<<n;
	cout << endl;
	*/
	string num;
	cin >> num;
	
	sort(num.begin(), num.end(), greater<int>());

	cout << num << endl;
}
