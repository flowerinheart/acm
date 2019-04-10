//一个字符串中的最长回文子串

//暴力搜索所有的子串，n^3

//动态规划,  P(i, j) = P(i + 1, j - 1) && s[i] == s[j]

//Expand Around Center, 思路类似动态规划，在每个点向两边展开， 总共可能有2n - 1种中心（因为可以从空向两边拓展)

public String longestPalindrome(String s) {
    if (s == null || s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = Math.max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substring(start, end + 1);
}

private int expandAroundCenter(String s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
        L--;
        R++;
    }
    return R - L - 1;
}

更加简洁的写法是
//一个优化方法是， 特殊优化中间都是相等的情况， 跳过一些
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxL = 0; 
        for (int i = 0; i < n;) {
            int l  = i, r = i;
            while (r < n - 1 && s[r] == s[r + 1]) 
                ++r;
            i = r + 1;
            while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]) {
                --l;
                ++r;
            }
            if (maxL < r - l + 1) {
                maxL = r - l + 1;
                start = l;
            }
        }
        return s.substr(start, maxL);
    }
};
//最简化版本
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxL = 0; 
        for (int i = 0; i < n;) {
            int l = i;
            for(i = i + 1; i < n && s[i] == s[i - 1];i++); 
            int r = i - 1;
            do 
                maxL = (r - l + 1) > maxL ? r - (start = l) + 1 : maxL;
            while (l > 0 && r < n - 1 && s[--l] == s[++r]);
        }
        return s.substr(start, maxL);
    }
};
// Manacher's Algorithm， o(n)但是很复杂，不建议直接写
// 
https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/