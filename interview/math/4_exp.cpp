

//计算base^exp, 其中exp可以是负数
class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1;
        int flag = exponent < 0 ? -1 : 1;
        exponent = exponent < 0 ? -exponent : exponent;
        for(int i = 0; i < exponent; i++)
            res *= base;
        return flag < 0 ? 1 / res : res;
    }
};