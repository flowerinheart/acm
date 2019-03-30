
//就是一些木板，高低不同，让你求容纳的雨量



//暴力求解的方法，对于每个元素，找到它的左边界和右边界，然后计算对应的雨量
int trap(vector<int>& height)
{
    int ans = 0;
    int size = height.size();
    for (int i = 1; i < size - 1; i++) {
        int max_left = 0, max_right = 0;
        for (int j = i; j >= 0; j--)  //Search the left part for max bar size
            max_left = max(max_left, height[j]);
        for (int j = i; j < size; j++)  //Search the right part for max bar size
            max_right = max(max_right, height[j]);
        ans += min(max_left, max_right) - height[i];
    }
    return ans;
}

//基于动态规划，可以快速的算出左边界和右边界，从而优化到o(n)
int trap(vector<int>& height)
{
	if(height == null)
		return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}


//双指针法， 类似于动态规划，但是做边界和右边界其实每次只有一个起作用，所以只需要交替的更新就好了
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}



// 关键思想就是，对于一个木板，它左侧所能形成的雨水区间，是左侧第一个大于等于它的木板，这就刚好符合单调栈的性质
// 我们维护一个递减栈
class Solution {
    public int trap(int[] height) {
        Stack<Integer> s = new Stack<Integer>();
        int res = 0, cur = 0;
        while(cur < height.length) {
            while(!s.empty() && height[cur] > height[s.peek()]) {//将比当前位置低的都出栈，
                int top = s.pop();
                if(s.empty())
                    break;
                int w = cur - s.peek() - 1;//从左边界到右边界的位置中都可以看做高度是height[top], 所以宽度是两个边界间的长度
                int h = Math.min(height[s.peek()], height[cur]) - height[top];//高度则是左右边界最小值减去height[top]
                res += w * h;
            }
            s.push(cur);
            cur++;
        }
        return res;
    }
}