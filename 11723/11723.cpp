#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

int set = 0;

int add(int element){
	set |= 1<<element;
	return -1;
}
int remove(int element){
	set &= ~(1<<element);
	return -1;
}
int check(int element){
	return (set & (1<<element)) ? 1 : 0;
}
int toggle(int element){
	set ^= 1<<element;
	return -1;
}
int all(int element){
	set = INT_MAX;
	return -1;
}
int empty(int element){
	set = 0;
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string instructions[6] = {"add", "remove", "check", "toggle", "all", "empty"};
	int (*funct_ptr[6])(int) = {add, remove, check, toggle, all, empty};
	string cmd;
	int M, element, ret;

	cin >> M;

	while(M--){
		cin >> cmd;
		for(int i=0;i<6;i++){
			if(cmd == instructions[i]){
				if(i < 4)
					cin >> element;
				ret = funct_ptr[i](element);
				if(ret != -1)
					cout << ret << "\n";
				break;
			}
		}
	}
}
