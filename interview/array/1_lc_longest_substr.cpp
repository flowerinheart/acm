//leetcode 3. Longest Substring Without Ryyepeating Characters


static int fast_io = []() { 
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pre[128];
        std::fill_n(pre, 128, -1);
        int res = 0, left = -1;
        for(int i = 0; i < s.size(); i++) {
            int c = s[i];
            left = max(left, pre[c]);
            res = max(res, i - left);
            pre[c] = i;
        }
        return res;
    }
};