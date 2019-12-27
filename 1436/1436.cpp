#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int cnt = 0;
	for(int i=666; 1; i++){
		string val = to_string(i);
		for(int j=0;j<val.length()-2;j++){
			if(val.substr(j,3) == "666"){
				cnt++;
				break;
			}
		}
		if(cnt == N){
			cout << i << endl;
			return 0;
		}
	}
}
