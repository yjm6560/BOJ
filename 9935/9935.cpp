#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

int main()
{
	vector<char> check;
	string keyword;
	string sentence;
	cin >> sentence >> keyword;
	int i, j, count = 0;
	int outCount = 0;
	if(keyword.size() == 1){
		for(i=0;i<sentence.length();i++){
			if(sentence[i] == keyword[0])
				continue;
			printf("%c",sentence[i]);
			outCount++;
		}
	}
	else{
		for(i=0;i<sentence.length();i++){
			check.push_back(sentence[i]);
			if(sentence[i] != keyword[count] && sentence[i] != keyword[0]){
				for(j=0;j<check.size();j++){
					printf("%c",check[j]);
				}
				outCount += check.size();
				check.clear();
				count = 0;
				continue;
			}
			count++;
			if(sentence[i] == keyword[0]){
				count = 1;
				continue;
			}
			if(sentence[i] == keyword[keyword.size()-1]){
				for(j=0;j<keyword.size();j++){
						check.pop_back();
				}
				if(check.empty()){
					count = 0;
				continue;
				}
				for(j=0;j<keyword.size();j++){
					if(check.back() == keyword[j]){
						count = j+1;
						break;
					}
				}
			}
		}
	}
	for(i=0;i<check.size();i++){
		printf("%c",check[i]);
		outCount++;
	}
	if(outCount == 0) printf("FRULA");
}
