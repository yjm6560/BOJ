#include <iostream>
#include <vector>

using namespace std;

#define PB push_back

typedef vector<int> vi;

int T, n, input;

vi sticker[2];
vi result[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				cin >> input;
				sticker[i].PB(input);
				result[i].PB(input);
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<2;j++){
				result[1-j][i+1] = max(result[1-j][i+1], result[j][i] + sticker[1-j][i+1]);
				if(i < n-2)
					result[1-j][i+2] = max(result[1-j][i+2], result[j][i] + sticker[1-j][i+2]);
			}
		}

		cout << max(result[0][n-1], result[1][n-1]) << endl;

		for(int i=0;i<2;i++){	
			sticker[i].clear();
			result[i].clear();
		}
	}
}
