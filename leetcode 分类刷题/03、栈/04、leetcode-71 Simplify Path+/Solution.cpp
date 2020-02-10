// 20. 有效的括号
// https://leetcode-cn.com/problems/valid-parentheses/
// 时间复杂度: O(n)
// 空间复杂度: O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++){
        	if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
        		stk.push(s[i]);
			}else{
				if(stk.empty())	return false;
				char c = stk.top();
				stk.pop();

				char m;
				if(s[i] == ')')	m = '(';
				else if(s[i] == ']')	m = '[';
				else	m = '{';

				if(c != m)	return false;
			}
		}
        return stk.empty();
    }
};
