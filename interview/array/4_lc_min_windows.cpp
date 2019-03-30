

// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//采用滑动窗口的思想
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(n < m)
            return "";
        
        
        vector<int> records(128, 0);
        int unmatch = m;
        for(char c : t)
            records[c]++;
        
        int b = 0, e = 0;
        int minLen = INT_MAX;
        int minB = -1;
        while(e < n){
            if(records[s[e++]]-- > 0)
                unmatch--;
            while(unmatch == 0){
                if(records[s[b++]]++ == 0) {
                    if(e - b + 1 < minLen){
                        minLen =  e - b + 1;
                        minB = b - 1;
                    }
                    unmatch++;
                }
            }
        }
        
        return minB == -1 ? "" : s.substr(minB, minLen);
    }
};