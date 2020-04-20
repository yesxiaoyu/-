// Author : lihongyu
// Time   : 2019-11-15

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    //sd为数据栈， ss表示辅助栈。若入栈value大于ss栈顶元素则入栈ss栈顶元素。
    stack<int> sd, ss;
    void push(int value) {
        sd.push(value);
        if(ss.size() == 0 || value < ss.top())    ss.push(value);
        else    ss.push(ss.top());
    }
    void pop() {
        sd.pop();
        ss.pop();
    }
    int top() {
        return sd.top();
    }
    int min() {
        return ss.top();
    }
};

int main(int argc, char* argv[])
{
	
    return 0;
}