/*
 * DP 
 *
 */

class Solution {
public:
    int checkRecord(int n) {
        int M = 1000000007;
        vector<int> P(n), L(n), A(n);
        P[0] = 1; L[0] = 1; L[1] = 3;
        A[0] = 1; A[1] = 2; A[2] = 4;
        for (int i = 1; i < n; ++i) {
            P[i] = ((P[i - 1] + L[i - 1]) % M + A[i - 1]) % M;
            if (i > 1) L[i] = ((A[i - 1] + P[i - 1]) % M + (A[i - 2] + P[i - 2]) % M) % M;
            if (i > 2) A[i] = ((A[i - 1] + A[i - 2]) % M + A[i - 3]) % M;
        }
        return ((A[n - 1] + P[n - 1]) % M + L[n - 1]) % M;
    }
};

// Conclusion:
// 
// Idea:
// 定义了三个DP数组P, L, A，其中P[i]表示数组[0,i]范围内以P结尾的所有排列方式，L[i]表示数组[0,i]范围内以L结尾的所有排列方式，
// A[i]表示数组[0,i]范围内以A结尾的所有排列方式。那么最终我们所求的就是P[n-1] + L[n-1] + A[n-1]了。那么难点就是分别求出P, 
// L, A数组的递推公式了。
// 
// 首先来看P数组的，P字符没有任何限制条件，可以跟在任何一个字符后面，所以有 P[i] = A[i-1] + P[i-1] + L[i-1]
//
// 再来看L数组的，L字符唯一的限制条件是不能有超过两个连续的L，那么在P和L字符后面可以加1一个L，如果前一个字符是L，我们要看再前面
// 的一位是什么字符，如果是P或着A的话，可以加L，如果是L的话，就不能再加了，否则就连续3个了，所以有 
// L[i] = A[i-1] + P[i-1] + A[i-2] + P[i-2]
// 
// 最后来看A数组的，这个比较麻烦，字符A的限制条件是整个字符串最多只能有1个A，那么当前一个字符是A的话，就不能再加A来，当前一个字
// 符是P或者L的话，要确定之前从没有A出现过，才能加上A。那么实际上我们还需要定义两个数组P1, L1, 其中P1[i]表示数组[0,i]范围内以
// P结尾的不包含A的所有排列方式，L1[i]表示数组[0,i]范围内以L结尾的不包含A的所有排列方式，根据前两种情况我们不难推出P1和L1的递
// 推公式，再加上A的递推公式如下：
// A[i] = P1[i-1] + L1[i-1]
// P1[i] = P1[i-1] + L1[i-1]
// L1[i] = P1[i-1] + P1[i-2]
//
// 将第二第三个等式多次带入第一个等式，就可以将P1和L1消掉，可以化简为：
// A[i] = A[i-1] + A[i-2] + A[i-3]
// 这样就可以少定义两个数组了，

// Reference:
// Leetcode discussion: https://leetcode.com/problems/student-attendance-record-ii/discuss/101643/Share-my-O(n)-C++-DP-solution-with-thinking-process-and-explanation
// Grandyang: http://www.cnblogs.com/grandyang/p/6866756.html




