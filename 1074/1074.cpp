/*
	Z
	분할정복
*/
#include <iostream>

using namespace std;

int n, r, c;

int solve(int x, int y, int size){
	if(size == 0)
		return 0;
	if(r>=x && r<x+size && c>=y && c<y+size){
		//1 sector
		return solve(x, y, size/2);
	} else if(r>=x && r<x+size && c>=y+size){
		//2 sector
		return size*size + solve(x, y+size, size/2);
	} else if(r>=x+size && c>=y && c<y+size){
		//3 sector
		return size*size*2 + solve(x+size, y, size/2);
	} else {
		//4 sector
		return size*size*3 + solve(x+size, y+size, size/2);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> c;
	int size = 1;
	for(int i=1;i<n;i++)
		size *= 2;
	cout << solve(0, 0, size) << endl;
}
