
//leetcode 
//30. Substring with Concatenation of All Words
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n1 = s.size(), n2 = words.size();
        vector<int> res;
        if(n2 == 0 || n1 == 0)
            return res;
        int k = words[0].size();
        int length = n2 * k;//target length
        if(n1 < length)
            return res;
        
        //count and dic for string s
        unordered_map<string, int> dic;
        vector<int> count;
        int i = 0;
        for(auto str : words) {
            if(dic.find(str) == dic.end()) {
                dic[str] = i++;
                count.push_back(1);
            } else
                count[dic[str]]++; 
        }
        int str_num = dic.size();

        //sliding windows
        int left = 0, right = 0;//sliding windows
        int* tcount = new int[str_num];//count for sliding windows
        auto process = [&]() { 
            //这个函数用来更新滑动窗口
            string str = s.substr(right, k);
            if(dic.find(str) == dic.end()) {
                fill_n(tcount, str_num, 0);
                left = right = right + k;
                return;
            }
            int no = dic[str];
            tcount[no]++;
            right += k;
            if(tcount[no] > count[no]) {
                while(tcount[no] > count[no]) {
                    //if(left + k > n1){
                    //res.push_back(count[no]);
                    //res.push_back(count[no] * 100);
                    //    return;
                    //}
                    tcount[dic[s.substr(left, k)]]--;
                    left += k;
                }
            } else if(right - left == length){//match
                res.push_back(left);
                tcount[dic[s.substr(left, k)]]--;
                left += k;
            }
        };
        
        for(i = 0; i < k; i++) {
            //k个单位, k个单位的处理，所以只需要迭代前k个节点就可以了
            fill_n(tcount, str_num, 0);

            //确定好起始点后，就只需要不断地更新滑动窗口就行了
            for(left = i, right = i; left + length <= n1;) 
                process();
        }
        return res;  
}
};