//青蛙跳台阶

//跳台阶1， 一次只能跳一层或者两层

class Solution {
public:
    int jumpFloor(int number) {
        int a = 1, b = 1;
        for(int i = 0; i < number; i++) {
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        return a;
    }
};
//跳台阶2， 可以跳任意层


class Solution {
public:
    int jumpFloorII(int number) {
        return pow(2, number - 1);
    }
};