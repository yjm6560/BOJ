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

	int N, S, input, sum = 0, best = 100001;
	vi nums;

	cin >> N >> S;
	while(cin >> input) nums.PB(input);

	for(int i=0;i<N;i++){
		sum += nums[i];
		if(sum >= S){
			best = dist(0,i);
			break;
		}
	}

	int end, beg = 0;
	if(best == N){
		while((sum - nums[beg]) >= S)
			sum -= nums[beg++];
		best = min(best, dist(beg, best-1));
	}
	else {
		for(end=best;end<N;end++){
			sum += nums[end];
			while((sum - nums[beg]) >= S){
				sum -= nums[beg++];
			}
			best = min(best, dist(beg, end));
		}
	}
	cout << (best == 100001? 0:best) << endl;
}
