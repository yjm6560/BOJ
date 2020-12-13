/*
	에디터
	스택
*/
#include <iostream>
#include <vector>
#include <string>

#define PB push_back
#define DE pop_back

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string input;
	vector<char> s1, s2;
	char cmd, val;
	int n;

	cin >> input;
	cin >> n;

	for(auto x : input)
		s1.PB(x);

	while(n--){
		cin >> cmd;
		switch(cmd){
			case 'L':
				if(!s1.empty()){
					s2.PB(*(s1.end()-1));
					s1.DE();
				}
				break;
			case 'D':
				if(!s2.empty()){
					s1.PB(*(s2.end()-1));
					s2.DE();
				}
				break;
			case 'B':
				if(!s1.empty())
					s1.DE();
				break;
			case 'P':
				cin >> val;
				s1.PB(val);
				break;
			default:
				break;
		}
	}
	for(auto x : s1)
		cout << x;
	for(int i=s2.size()-1;i>=0;i--)
		cout << s2[i];
	cout << endl;
}
