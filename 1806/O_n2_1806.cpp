#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define PB push_back
#define dist(a, b) b-a+1

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, S, input, best = 100001;
	vi nums;

	cin >> N >> S;
	while(cin >> input) nums.PB(input);
/*		
	for(int i=0;i<N;i++){
		int sum = 0;
		for(int j=i;j<N && dist(i,j)<best;j++){
			sum += nums[j];
			if(sum >= S){
				best = dist(i,j);
				break;
			}
		}
	}
*/
	int sum = 0;
	for(int i=0;i<N;i++){
		sum += nums[i];
		if(sum >= S){
			best = dist(0,i);
			cout << sum << " " << best << endl;
			break;
		}
	}
	if(best == 100001){
		cout << "First " << 0 << "\n";
		return 0;
	}
int end, beg = 0;
	for(end=best-1;end<N;end++){
		sum += nums[++end];
		while((sum - nums[beg]) >= S){
			cout << "\t" << sum << " " << S << endl;
			sum -= nums[beg];
			beg++;
		}
		cout << beg << " to " << end << " sum : " << sum << endl;
		best = min(best, dist(beg, end));
	}
	cout << (best == 100001? 0:best) << endl;
}
