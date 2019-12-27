#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<char> tmxor;
	string str;
	int i;
	while(true){
		getline(cin, str);
		if(str.length() == 1 && str[0] =='.')
			break;
		for(i=0; i<str.length(); i++){
			char c = str[i];
			if(c == '(') tmxor.push('(');
			else if(c == '[') tmxor.push('[');
			else if(c == ')'){
				if(!tmxor.empty() && tmxor.top() == '(')
					tmxor.pop();
				else
					break;
			}
			else if(c == ']'){
				if(!tmxor.empty() && tmxor.top() == '[')
					tmxor.pop();
				else
					break; 
			}
		}
		if(tmxor.empty() && i == str.length())
			printf("yes\n");
		else
			printf("no\n");
		while(!tmxor.empty()) tmxor.pop();
	}
}
