#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> stack;
	int n, val;
	string cmd;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> cmd;
		if(!cmd.compare("push")){
			cin >> val;
			stack.push_back(val);
		} else if(!cmd.compare("pop")){
			if(stack.empty()){
				cout << -1 << endl;
			}
			else{
				cout << stack.back() << endl;
				stack.pop_back();
			}
		} else if(!cmd.compare("size")){
			cout << stack.size() << endl;
		} else if(!cmd.compare("empty")){
			cout << (stack.empty() ? 1 : 0) << endl;
		} else if(!cmd.compare("top")){
			cout << (stack.empty() ? -1 : stack.back()) << endl;
		}
	}
}
