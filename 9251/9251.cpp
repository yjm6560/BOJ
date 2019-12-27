#include <iostream>

using namespace std;

string a, b;
int arr[1000][1000];

int lcs(int x, int y){
	if(x == -1 || y == -1)
		return 0;
	else if(arr[x][y] == -1){
		if(a[x] == b[y])
			arr[x][y] = lcs(x-1, y-1)+1;
		else{
			int tmp1 = lcs(x-1, y);
			int tmp2 = lcs(x, y-1);
			if(tmp1 > tmp2) arr[x][y] = tmp1;
			else arr[x][y] = tmp2;
		}
	}
	return arr[x][y];	
}
int main()
{
	cin >> a >> b;
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
			arr[i][j] = -1;
	lcs(a.length()-1, b.length()-1);
	cout << arr[a.length()-1][b.length()-1] << endl;
}
