package com.company;

class Solution {
    public int maxArea(int[] height) {
        int res = 0;
        int l = 0, r = height.length - 1;
        while (l < r) {
            int area = Math.min(height[l], height[r]) * (r - l);
            res = Math.max(area, res);
            if (height[r] > height[l])
                l++;
            else
                r--;
        }
        return res;
    }
}

public class Main {

    public static void main(String[] args) {
	    int[] arr = {1,8,6,2,5,4,8,3,7};
	    System.out.println(new Solution().maxArea(arr)); // 49
    }
}
