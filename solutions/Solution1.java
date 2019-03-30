import java.util.HashMap;
class Solution1 {
    // 判断两个字符串是否只有顺序不一致：例如 "rabbit"和"batrib"符合描述， “rabbit”和“batreb”不符合描述
    //如果只有顺序不一致，字母组合一致就返回true, 否则返回false
    public int match(String str1, String str2) {
        if(str1.equals(str2))
            return false;
        if(str1.length != str2.length)
            return false;
        HashMap<Character, Integer> m1 = new HashMap<Character, Integer>();
        for(int i = 0; i < str1.size(); i++) {
            char c = str1.charAt(i);
            if(m1.containsKey(c))
                m1.put(c, m1.get(c) + 1);
            else
                m1.put(c, 1);
        }
        for(int i = 0; i < str2.size(); i++) {
            char c = str2.charAt(i);
            if(m2.containsKey(c))
                m2.put(c, m2.get(c) - 1);
            else
                return false;
        }
        //如果两个字符串字母组合完全相同，那么最后每个key的值都是0
        for(char key : m1.keySet()) 
            if(m2.get(key) != 0)
                return false;
        return true;
    }
}


