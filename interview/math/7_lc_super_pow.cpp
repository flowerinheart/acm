


// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
class Solution {
public:
    int pow(int base, int pow) {
        int res = 1;
        while(pow != 0) {
            if(pow & 1)
                res = res * base % 1337;
            base = base * base % 1337;
            pow = pow >> 1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int base = a % 1337;
        int res = 1;
        for(int i = b.size() - 1; i >= 0; i--) {
            int num = b[i];
            if(num != 0) 
                res = pow(base, num) * res % 1337;
            base = pow(base, 10);
        }
        return res;
    }
};