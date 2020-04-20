// Author : lihongyu
// Time   : 2020-2-23
// leetcode-79 单词搜索
// 思路：回溯法
// 时间复杂度: O(m*n*m*n)
// 空间复杂度: O(m*n)
class Solution {
    private static final int[][] next = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    private int cnt = 0;
    private int m;
    private int n;
    private int k;
   
    public int movingCount(int m, int n, int k) {

        this.m = m;
        this.n = n;
        this.k = k;
        int cal;
        boolean[][] flag = new boolean[m][n];
        dfs(0,0,flag);
        return cnt;
    }
    private void dfs(int i, int j,boolean[][] flag ) {
     
        if (i < 0 || i >= m || j< 0 || j >= n || flag[i][j]) {
            return;
        }
        if(cal(i) + cal(j) > k) {
            return;
        }
        cnt++;
        flag[i][j] = true;
        for(int p = 0; p < 4; p++) {
            int newi= i + next[p][0];
            int newj= j + next[p][1];
            dfs(newi , newj , flag);
        }
    }
    private int cal(int num) {
        int ref = 0;
        while(num > 0) {
            ref += num % 10;
            num /= 10;
        }
        return ref;
    }
}


// TODO: