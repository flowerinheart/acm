//计算一个数中1的个数
class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int v = n;
         int res = 0;
         while(v != 0) {
             res += v & 1;
             v = v >> 1;
         }
         return res;
     }
};


//计算小于n的整数所有1的个数和

class Solution {
    public int countDigitOne(int n) {
        int res = 0;
        int m = 1;
        while(true) {
            int a = n / m, b = n % m;
            res += (a + 8) / 10 * m + (((a % 10) == 1) ? b + 1 : 0);
            if(m > n / 10)
                break;
            m = m * 10;
        }
        return res;
    }
}