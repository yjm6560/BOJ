#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	vector<string> s = {"유", "지", "읽", "안"};

	for(auto x : s)
		cout << x << " length = " << x.length() << endl;
	return 0;
}
