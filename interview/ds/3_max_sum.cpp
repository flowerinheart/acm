//求一个数组中，一个连续区间，它的和乘以最小值最大
//思路就是对于a[i], 假设左边第一个大于a[i]的是left, 右边是right, 那么在[left, right]中a[i]都是最小值，问题就简化成了计算a[i] * sum的最大值
//具有这种性质的问题一般都可以用dp或者单调栈

int incr_stack(vector<int> &num) {
    stack<int> s;
    int sum = 0;
    int maxSum = INT_MIN;
    num.push_back(0); // 用于清除栈中剩余的
    int n = num.size();
    for (int i = 0; i < n; i++) {
        if (s.empty() || num[i] >=num[s.top()]) //规则1
            s.push(i);
        else {
            int top = s.top();
            int left = s.empty() ? 0 : s.top() + 1;
            maxSum = max(maxSum, vecSum(num, left, i - 1) * num[top]);
        }
    }
    return maxSum;
}


//同理dp也可以解决，这里就不讲了