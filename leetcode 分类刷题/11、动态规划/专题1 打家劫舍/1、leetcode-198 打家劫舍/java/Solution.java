import java.util.Arrays;

/// 198. House Robber
/// https://leetcode.com/problems/house-robber/description/
/// 记忆化搜索
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
public class Solution {

    // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益
    private int[] memo;

    public int rob(int[] nums) {
        memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return tryRob(nums, 0);
    }

    // 考虑抢劫nums[index...nums.size())这个范围的所有房子
    private int tryRob(int[] nums, int index){

        if(index >= nums.length)
            return 0;

        if(memo[index] != -1)
            return memo[index];

        int res = 0;
        for(int i = index ; i < nums.length ; i ++)
            res = Math.max(res, nums[i] + tryRob(nums, i + 2));
        memo[index] = res;
        return res;
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution1()).rob(nums));
    }
}

/// 198. House Robber
/// https://leetcode.com/problems/house-robber/description/
/// 动态规划
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
public class Solution2 {

    public int rob(int[] nums) {

        int n = nums.length;
        if(n == 0)
            return 0;

        // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益
        int[] memo = new int[nums.length];
        memo[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i --)
            for (int j = i; j < n; j++)
                memo[i] = Math.max( memo[i],
                                    nums[j] + (j + 2 < n ? memo[j + 2] : 0));

        return memo[0];
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution2()).rob(nums));
    }
}

/// 记忆化搜索, 改变状态定义
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
public class Solution3 {

    // memo[i] 表示考虑抢劫 nums[0...i] 所能获得的最大收益
    private int[] memo;

    public int rob(int[] nums) {
        memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return tryRob(nums, nums.length - 1);
    }

    // 考虑抢劫nums[0...index]这个范围的所有房子
    private int tryRob(int[] nums, int index){

        if(index < 0)
            return 0;

        if(memo[index] != -1)
            return memo[index];

        int res = 0;
        for(int i = 0 ; i <= index ; i ++)
            res = Math.max(res, nums[i] + tryRob(nums, i - 2));
        memo[index] = res;
        return res;
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution3()).rob(nums));
    }
}

/// 动态规划, 改变状态定义
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
public class Solution4 {

    public int rob(int[] nums) {

        int n = nums.length;
        if(n == 0)
            return 0;

        // memo[i] 表示考虑抢劫 nums[0...i] 所能获得的最大收益
        int[] memo = new int[nums.length];
        memo[0] = nums[0];
        for(int i = 1 ; i < n ; i ++)
            for (int j = i; j >= 0; j--)
                memo[i] = Math.max(memo[i],
                                   nums[j] + (j - 2 >= 0 ? memo[j - 2] : 0));

        return memo[n-1];
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution4()).rob(nums));
    }
}

/// 记忆化搜索, 优化状态转移
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)
public class Solution5 {

    // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益
    private int[] memo;

    public int rob(int[] nums) {
        memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return tryRob(nums, 0);
    }

    // 考虑抢劫nums[index...nums.size())这个范围的所有房子
    private int tryRob(int[] nums, int index){

        if(index >= nums.length)
            return 0;

        if(memo[index] != -1)
            return memo[index];

        // 或者当前房子放弃, 从下一个房子开始考虑
        // 或者抢劫当前的房子, 从i+2以后的房子开始考虑
        return memo[index] =
                Math.max(tryRob(nums, index + 1),
                         nums[index] + tryRob(nums, index + 2));
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution5()).rob(nums));
    }
}

/// 动态规划, 优化状态转移
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)
public class Solution6 {

    public int rob(int[] nums) {

        int n = nums.length;
        if(n == 0)
            return 0;

        // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益
        int[] memo = new int[nums.length];
        memo[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i --)
            // 或者当前房子放弃, 从下一个房子开始考虑
            // 或者抢劫当前的房子, 从i+2以后的房子开始考虑
            memo[i] = Math.max(memo[i + 1],
                               nums[i] + (i + 2 < n ? memo[i + 2] : 0));

        return memo[0];
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution6()).rob(nums));
    }
}

/// 记忆化搜索, 改变状态定义, 优化转移方程
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)
public class Solution7 {

    // memo[i] 表示考虑抢劫 nums[0...i] 所能获得的最大收益
    private int[] memo;

    public int rob(int[] nums) {
        memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return tryRob(nums, nums.length - 1);
    }

    // 考虑抢劫nums[0...index]这个范围的所有房子
    private int tryRob(int[] nums, int index){

        if(index < 0)
            return 0;

        if(memo[index] != -1)
            return memo[index];

        // 或者当前房子放弃, 考虑[0...index-1]的所有房子
        // 或者抢劫当前的房子, 考虑[0...index-2]的所有房子
        return memo[index] =
                Math.max(tryRob(nums, index - 1),
                         nums[index] + tryRob(nums, index - 2));
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution7()).rob(nums));
    }
}

/// 动态规划, 改变状态定义, 优化转移方程
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)
public class Solution8 {

    public int rob(int[] nums) {

        int n = nums.length;
        if(n == 0)
            return 0;

        // memo[i] 表示考虑抢劫 nums[0...i] 所能获得的最大收益
        int[] memo = new int[nums.length];
        memo[0] = nums[0];
        for(int i = 1 ; i < n ; i ++)
            memo[i] = Math.max(memo[i - 1],
                               nums[i] + (i - 2 >= 0 ? memo[i - 2] : 0));

        return memo[n-1];
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution8()).rob(nums));
    }
}