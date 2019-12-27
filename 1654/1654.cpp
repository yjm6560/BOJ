#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

long long haveLine, needLine, minLine = 0;
vector<long long > line;
long long unitLine;

long long cal(long long unit){
	long long sum = 0;
	for(long long i=0;i<line.size();i++)
		sum += line[i]/unit;
	return sum;
}

void binarySearch(long long low, long long high){
	unitLine = (low + high)/2;
	//printf("low %lld high %lld cal(unitLine) %lld\n", low, high, cal(unitLine));
	if(high - low <= 1) return;
	if(cal(unitLine) >= needLine){
		binarySearch(unitLine, high);
	}
	else{
		binarySearch(low, unitLine);
	}
}
int main()
{
	cin >> haveLine >> needLine;
	cin >> minLine;
	line.push_back(minLine);
	for(long long i=1;i<haveLine;i++){
		long long tmp;
		scanf("%lld",&tmp);
		line.push_back(tmp);
		if(minLine < tmp){minLine = tmp;}
	}
	//for(long long i=0;i<line.size();i++)
	//	printf("%lld, ",line[i]);
	//printf("\n");
	binarySearch((long long)1, minLine);
	printf("%lld\n", cal(unitLine) < needLine ? unitLine-1 : cal(unitLine+1) < needLine? unitLine : unitLine+1 );
	
}
