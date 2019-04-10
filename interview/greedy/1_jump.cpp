
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.

//思路就是维护当前能到达的新区域，然后从中更新
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int a = 0, b = 0;
        while(true) {
            int maxv = -1;
            for(int i = a; i <= b; i++) { 
                maxv = max(maxv, nums[i] + i); 
                if(maxv >= nums.size() - 1)
                    return true;
            }
            if(maxv <= b)
                break;
            a = b + 1;
            b = maxv;
        }
        return false;
    }
};


//稍微变种一下，返回到达目的地的最少跳数
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int a = 0, b = 0;
        int count = 0;
        while(b < nums.size() - 1) {
            int maxv = -1;
            count++;
            for(int i = a; i <= b; i++) { 
                maxv = max(maxv, nums[i] + i); 
                if(maxv >= nums.size() - 1)
                    return count;
            }
            if(maxv <= b)
                break;
            a = b + 1;
            b = maxv;
        }
        return -1;      
    }
};