// [LeetCode] Largest Rectangle in Histogram 
//简单来说就是给n个并列的长条，返回长条构成的最大的矩形的面积，比如

//     --
// --  -- 
// --  --  --

//上面这个就是4


//注意按照单调栈的第四个性质，当要出栈的时候，
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[st.top()] < height[i]) {
                st.push(i);
            } else {
                int cur = st.top(); st.pop();//这里可以肯定的一点是, cur就是i-1
                res = max(res, height[cur] * (st.empty() ? i : (cur - st.top()))); //按照中间夹得都大于两边的性质，宽度就是cur - st.top()
                --i;
            }     
        }
        return res;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top(); st.pop();
                //按照中间夹得都大于两边的性质，宽度就是i - 1 - st.top()
                res = max(res, heights[cur] * (st.empty() ? i : (i - 1 - st.top())));
            }
            st.push(i);
        }
        return res;
    }
};




//关键思想是将问题转换成以h[i]为顶部的最大矩阵中，最大的面积是多少， 有了这个思路可以考虑用dp,或者二分来优化

// 比较利于理解的做法是，对于第i个方块，以他作为桶顶部的矩阵块，左右边界分别是最左/右边连续大于h[i]的最后一个节点， 
// 举个例子  1, 2, 3, 2, 3, 4, 1, 对于h[3], 左右边界分别是1和5
//那么就可以通过暴力求解完成，如下所示


// int maxArea = 0;
// for (int i = 0; i < height.length; i++) {
//     maxArea = Math.max(maxArea, height[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
// }

// 而lessFromRight/Left可以通过动态规划计算出来, 最终的解法如下

public static int largestRectangleArea(int[] height) {
    if (height == null || height.length == 0) {
        return 0;
    }
    int[] lessFromLeft = new int[height.length]; // idx of the first bar the left that is lower than current
    int[] lessFromRight = new int[height.length]; // idx of the first bar the right that is lower than current
    lessFromRight[height.length - 1] = height.length;
    lessFromLeft[0] = -1;

    for (int i = 1; i < height.length; i++) {
        int p = i - 1;
        while (p >= 0 && height[p] >= height[i]) 
            p = lessFromLeft[p];
        lessFromLeft[i] = p;
    }

    for (int i = height.length - 2; i >= 0; i--) {
        int p = i + 1;
        while (p < height.length && height[p] >= height[i]) 
            p = lessFromRight[p];
        lessFromRight[i] = p;
    }

    int maxArea = 0;
    for (int i = 0; i < height.length; i++) {
        maxArea = Math.max(maxArea, height[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
    }

    return maxArea;
}


//还有一种递归的做法, 从最小值划分成左右两部分, 此时左部分的矩阵不会越过最小值，但是这样子性能比较差

class Solution {
    public int largestRectangleArea(int[] heights) {
        return getMax(0, heights.length - 1, heights);
    }

    public int getMax(int left, int right, int[] heights) {
        if (left > right)
            return 0;
        else if (left == right)
            return heights[left];
        int minPos = left;
        boolean sorted = true;
        for (int i = left + 1; i <= right; i++) {
            if (heights[i - 1] > heights[i])
                sorted = false;
            if (heights[minPos] > heights[i])
                minPos = i;
        }
        if (sorted) {//这里对性能影响极大，因为如果这里不处理就会持续的去递归执行，性能很差，这边相当于提前剪枝
            int max = 0;
            for (int i = left; i <= right; i++)
                max = Math.max(max, (right - i + 1) * heights[i]);
            return max;
        }
        int leftmax = getMax(left, minPos - 1, heights);
        int rightmax = getMax(minPos + 1, right, heights);
        int localmax = heights[minPos] * (right - left + 1);
        return Math.max(localmax, Math.max(leftmax, rightmax));
    }
}