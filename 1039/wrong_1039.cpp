/*
	교환
	BFS, ?
*/
#include <iostream>
#include <string>

using namespace std;

string input;
int k;

int change(int num, int n, int cnt){
	if(cnt == k)
		return num;	

	int max = n;
	string s = to_string(num);
	if(n == s.length()){
		if((k-cnt)%2 == 0)
			return num;
		else {
			max = s.length()-1;
			n = s.length()-2;
			char tmp = s[n];
			s[n] = s[max];
			s[max] = tmp;
			return atoi(s.c_str());
		}
	} else {
		for(int i=n;i<s.length();i++){
			if(s[max] <= s[i]){
				max = i;
			}
		}
		char tmp = s[n];
		s[n] = s[max];
		s[max] = tmp;
		return change(atoi(s.c_str()), n+1, (max == n? cnt:cnt+1));
	}
}

int main()
{
	cin >> input >> k;
	int zero_cnt = 0;
	for(int i=0;i<input.length();i++)
		if(input[i] == '0') zero_cnt++;
	cout << input.length() << " and zero : " << zero_cnt << endl;
//	if(zero_cnt != input.length()-1){
	if(atoi(input.c_str())/10 == 0 || input.length() == 2 && zero_cnt == 1){
		cout << "-1\n";
	} else {
		cout << change(atoi(input.c_str()), 0, 0) << endl;
	}

}
