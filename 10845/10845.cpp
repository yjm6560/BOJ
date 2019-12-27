#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n, val;
	string cmd;
	vector<int> queue;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> cmd;
		if(!cmd.compare("push")){
			cin >> val;
			queue.push_back(val);
		} else if(!cmd.compare("pop")){
			if(queue.empty()){
				cout << -1 << endl;
			}
			else {
				cout << queue.front() << endl;
				queue.erase(queue.begin());
			}
		} else if(!cmd.compare("size")){
			cout << queue.size() << endl;
		} else if(!cmd.compare("empty")){
			cout << (queue.empty() ? 1 : 0) << endl;
		} else if(!cmd.compare("front")){
			cout << (queue.empty() ? -1 : queue.front()) << endl;;
		} else if(!cmd.compare("back")){
			cout << (queue.empty() ? -1 : queue.back()) << endl;
		}
	}
}
