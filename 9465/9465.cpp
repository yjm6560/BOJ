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
		for(int i=0;i<2*(n-1);i++){
			int row = i%2;
			int col = i/2;
			
			result[1-row][col+1] = max(result[1-row][col+1], result[row][col] + sticker[1-row][col+1]);
			if(col < n-2)
				result[1-row][col+2] = max(result[1-row][col+2], result[row][col] + sticker[1-row][col+2]);
		}

		cout << max(result[0][n-1], result[1][n-1]) << endl;

		for(int i=0;i<2;i++){	
			sticker[i].clear();
			result[i].clear();
		}
	}
}
