package com.company;

import java.util.Arrays;

// 4. 最小跳跃次数
// 为了给刷题的同学一些奖励，力扣团队引入了一个弹簧游戏机。游戏机由 N 个特殊弹簧排成一排，编号为 0 到 N-1。
// 初始有一个小球在编号 0 的弹簧处。若小球在编号为 i 的弹簧处，通过按动弹簧，可以选择把小球向右弹射 jump[i] 的距离，
// 或者向左弹射到任意左侧弹簧的位置。也就是说，在编号为 i 弹簧处按动弹簧，小球可以弹向 0 到 i-1 中任意弹簧
// 或者 i+jump[i] 的弹簧（若 i+jump[i]>=N ，则表示小球弹出了机器）。小球位于编号 0 处的弹簧时不能再向左弹。
//
// 为了获得奖励，你需要将小球弹出机器。请求出最少需要按动多少次弹簧，可以将小球从编号 0 弹簧弹出整个机器，
// 即向右越过编号 N-1 的弹簧。
class Solution {
    public int minJump(int[] jump) {
        int res = 0;

        return res;
    }
}

public class Main {

    public static void main(String[] args) {
        int[] jump = {2, 5, 1, 1, 1, 1};
        System.out.println(new Solution().minJump(jump)); // 3  0 -> 2 -> 1 -> 6

    }
}
