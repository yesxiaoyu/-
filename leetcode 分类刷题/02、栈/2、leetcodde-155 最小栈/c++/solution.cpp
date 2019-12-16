// 155. 最小栈
// https://leetcode-cn.com/problems/min-stack/submissions/
// 时间复杂度: O(1)
// 空间复杂度: O(1)

class MinStack {
public:
    /** initialize your data structure here. */
    
    MinStack() {
        
    }
    
    void push(int x) {
        sd.push(x);
        if(ss.size() == 0 || x < ss.top())    ss.push(x);
        else    ss.push(ss.top());
    }
    
    void pop() {
        sd.pop();
        ss.pop();
    }
    
    int top() {
        return sd.top();
    }
    
    int getMin() {
        return ss.top();
    }
private:
    //sd为数据栈， ss表示辅助栈。若入栈value大于ss栈顶元素则入栈ss栈顶元素。
    stack<int> sd, ss;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */