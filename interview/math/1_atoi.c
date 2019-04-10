
//将字符串转为int
//1. 考虑开头空格，考虑开头有+/-符号
//2. 采用无符号数保存数组的上下界，提前判断是否超界
//3. 判断数字有奇怪符号就返回

int myAtoi(char* str) {
    int len = strlen(str);
    if(len == 0)
        return 0;
    int i = 0;
    while (str[i] == ' ' && i < len)
        i++;
    int sign = 1;
    unsigned int max = INT_MAX;
    if (str[i] == '-' || str[i] == '+') {
        sign = str[i] == '-' ? -1 : 1;
        max = str[i] == '-' ? -(unsigned int)INT_MIN : (unsigned int)INT_MAX; 
        i++;
    }
    unsigned int rval = 0;
    for (; i<len; i++) {
        if (str[i] < '0' || str[i] > '9')
            break;
        if ((max - str[i] + '0') / 10 >= rval)
            rval = rval*10 + (unsigned int)(str[i] - '0');
        else
            return max;
    }
    return rval * sign;
}