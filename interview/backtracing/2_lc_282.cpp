Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

给定一串数字，和target
在这一串数字中插入"+-*"三种运算符，找出所有插入方式，使得运算结果等于target



class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> res=new ArrayList<>();
        backTrack(res,num,0,(long)target,0,"");
        return res;
    }
    public void backTrack(List<String> res,String num,int start,long target,long pre,String path){
        if(start==num.length()&&target==0) res.add(path);
        for(int i=start;i<num.length();i++){
            if(i!=start&&num.charAt(start)=='0') break;
            String temp=num.substring(start,i+1);
            long cur=Long.parseLong(temp);
            if(start==0){
                backTrack(res,num,i+1,target-cur,cur,path+cur);
            }
            else{
                backTrack(res,num,i+1,target-cur,cur,path+"+"+cur);
                backTrack(res,num,i+1,target+cur,-cur,path+"-"+cur);
                backTrack(res,num,i+1,target+pre-pre*cur,pre*cur,path+"*"+cur);
            }
        }
    }
}



最高效的做法

class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> res = new ArrayList();
        if(target <= Integer.MIN_VALUE) return res;
		char[] sc = num.toCharArray();
		char[] path = new char[sc.length * 2];
		int n = 0;
		for (int i = 0; i < sc.length; i++) {
			n = n * 10 + (sc[i] - '0');
			path[i] = sc[i];
			helper(res, sc, i + 1, path, i + 1, 0, n, target);
			if (n == 0)
			    break;
		}
		return res;
    }
    
    public void helper(List<String> res, char[] sc, int si, char[] path, int pi, int total, int cur, int target) {
        if(si == sc.length) {
            if(cur + total == target) {
                res.add(new String(path, 0, pi));
            }
            return;
        }
        int signIndex = pi;
        pi++;
        int n = 0;
        for(int i = si; i < sc.length; i++) {
            n = n * 10 + (sc[i] - '0');
            path[pi] = sc[i];
            pi++;
            path[signIndex] = '+';
            helper(res, sc, i+1, path, pi, total + cur, n, target);
            path[signIndex] = '-';
            helper(res, sc, i+1, path, pi, total + cur, -n, target);
            path[signIndex] = '*';
            helper(res, sc, i+1, path, pi, total, n * cur, target);
            if(n == 0)
                break;
        }
    }
  
}




class Solution {
public:
    //si, ti分别是两个字符串中的index
    void backtrace(vector<string> &res, string &num, int si, string &temp, int ti, 
                   int target, long val, long pre) {
        if(si == num.size()) {
            if(val + pre == target) {
                res.push_back(temp.substr(0, ti));
                return;
            }
        }
        long n = 0;
        for(int tsi = si, tti = ti + 1; tsi < num.size();) {
            n = n * 10 + (num[tsi] - '0');
            temp[tti++] = num[tsi++];
            temp[ti] = '+';
            backtrace(res, num, tsi, temp, tti, target, val + pre, n);
            temp[ti] = '-';
            backtrace(res, num, tsi, temp, tti, target, val + pre, -n);        
            temp[ti] = '*';
            backtrace(res, num, tsi, temp, tti, target, val, pre * n);
            if(n == 0)
                break;  
        }

    }
    
    
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string temp(num.size() * 2, '0');
        long n = 0;
        for(int i = 0; i < num.size(); i++) {
            n = n * 10 + (num[i] - '0');
            temp[i] = num[i];
            backtrace(res, num, i + 1, temp, i + 1, target, 0, n);
            if(n == 0)
                break;
        }
        return res;
    }
};