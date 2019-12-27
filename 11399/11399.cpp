#include <iostream>

using namespace std;

int main()
{
	int i, j, n, arr[1001];
	int wait = 0;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> arr[i];
	//do by insert sort
	for(i=0;i<n-1;i++){
		int min = i;
		for(j=i+1;j<n;j++){
			if(arr[min] > arr[j])
				min = j;
		}
		//swap
		int tmp = arr[min];
		arr[min] = arr[i];
		arr[i] = tmp;
		//increase wait value
		wait += (n-i)*arr[i];
	}
	wait += arr[n-1];
	cout << wait << endl;
}
