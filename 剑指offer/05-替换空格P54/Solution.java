// Author : lihongyu
// Time   : 2020-2-14
// leetcode-面试题05. 替换空格
// 思路：字符串
// 时间复杂度: O(n)
// 空间复杂度: O(1)

public class Solution {
    public String replaceSpace(String s) {
        StringBuilder res = new StringBuilder();
        for(Character c : s.toCharArray()) {
            if(c == ' ') 
                res.append("%20");
            else res.append(c);
        }
        return res.toString();
    }

    public static void main(String[] args) {

        String s = "We are happy.";
        String res = (new Solution()).replaceSpace(s);
        System.out.println(res);

    }
}


// TODO: