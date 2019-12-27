#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> tmxor;
    int K, tmp;
    int sum = 0;
    cin >> K;
    for(int i=0;i<K;i++){
        scanf("%d", &tmp);
        if(tmp == 0)
            tmxor.pop();
        else
            tmxor.push(tmp);
    }
    while(!tmxor.empty()){
        sum += tmxor.top();
        tmxor.pop();
    }
    printf("%d\n",sum);
}
