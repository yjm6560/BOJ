#include <iostream>

using namespace std;

int main()
{
	int tnf[10001];
	int aktlstnf[10001];
	int N;
	cin >> N;
	for(int i=1;i<=N;i++){
		scanf("%d", &tnf[i]);
	}
	tnf[0] = aktlstnf[0] = 0;
	aktlstnf[1] = tnf[1];
	aktlstnf[2] = tnf[1]+tnf[2];
	for(int i=3;i<=N;i++){
		int a = tnf[i] + tnf[i-1] + aktlstnf[i-3];
		int b = tnf[i] + aktlstnf[i-2];
		int c = aktlstnf[i-1];
		if(a >= b && a >= c) aktlstnf[i] = a;
		else if(b >= a && b >= c) aktlstnf[i] = b;
		else if(c >= a && c >= b) aktlstnf[i] = c;
	}
	cout << aktlstnf[N] << endl;
}
