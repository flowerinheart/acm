
//leetcode 3. Longest Substring Without Ryyepeating Characters
//Given a string, find the length of the longest substring without repeating characters.
//采用滑动窗口的思想， 每次拓展右边界，根据右边界的字符来重新更新左边界，这里用max方法，意思就是如果跟当前字符重复的上一个字符在当前滑动窗口内就更新滑动窗口（维持滑动窗口的无重复性质）
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] m = new int[256];
        Arrays.fill(m, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            left = Math.max(m[c], left);
            res = Math.max(res, i - left);
            m[s.charAt(i)] = i;
        }
        return res;
    }
}


