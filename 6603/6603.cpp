/*
	로또
	BFS
*/
#include <iostream>
#include <queue>

using namespace std;

#define LOTTO 6
#define REP(i,a,b) for(int i=a;i<=b;i++)


int k, input;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(true){
		cin >> k;
		if(k == 0)
			break;
		
		vector<int> num;
		int L[LOTTO];

		REP(i,1,k){
			cin >> input;
			num.push_back(input);
		}
		REP(a,0,k-LOTTO){
			REP(b,a+1, k-LOTTO+1){
				REP(c, b+1, k-LOTTO+2){
					REP(d, c+1, k-LOTTO+3){
						REP(e, d+1, k-LOTTO+4){
							REP(f, e+1, k-LOTTO+5){
								cout << num[a] << " " << num[b] << " " << num[c] << " " << num[d] << " " << num[e] << " " << num[f] << "\n";
							}
						}
					}
				}
			}
		}
		cout << "\n";
	}
}
