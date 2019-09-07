
//将阿拉伯数字转换成英文表示，注意点
//1. 处理单元是千， 每个千内部再单独处理
class Solution {
private final String[] LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
private final String[] TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
private final String[] THOUSANDS = {"", "Thousand", "Million", "Billion"};

public String numberToWords(int num) {
    if (num == 0) return "Zero";

    int i = 0;
    String words = "";
    
    while (num > 0) {
        if (num % 1000 != 0)
    	    words = helper(num % 1000) +THOUSANDS[i] + " " + words;
    	num /= 1000;
    	i++;
    }
    
    return words.trim();
}

private String helper(int num) {
    if (num == 0)
        return "";
    else if (num < 20)
        return LESS_THAN_20[num] + " ";
    else if (num < 100)
        return TENS[num / 10] + " " + helper(num % 10);
    else
        return LESS_THAN_20[num / 100] + " Hundred " + helper(num % 100);
}
}


// 数字转换成中文，主要区别在于处理单位变成了， 万亿兆
// CHINESE_NEGATIVE = '负'
// CHINESE_ZERO = '零'
// CHINESE_DIGITS = ['', '一', '二', '三', '四', '五', '六', '七', '八', '九']
// CHINESE_UNITS = ['', '十', '百', '千']
// CHINESE_GROUP_UNITS = ['', '万', '亿', '兆']

// 然后是“零”。在计数体系中，“零”跟其他数字可是有着本质区别的，在中文表达的时候，这种特殊性也非常明显，所以也单独分配一个常量。

// 数字“一二三四五六七八九”是十进制数字中，除零之外的基本字符，对应了除“0”之外的全部九个阿拉伯数字符号。用一个常量数组保存。它们的特点是构成了一个差值为1的等差数列。

// “十百千”是每个万组内的数位标识，是一个比值为10的等比数列。在这里大家可以看出为什么不把“十”跟上一组汉字放在一起。

// 最后是“万亿兆”，是比值为10^4的等比数列。实际上后面还可以继续写下去（参见个十百千万亿兆后面是什么），比如10^16用“京”表示



特殊的“0”
目前主要的问题在于对“0”的处理上，上面的程序忽略了所有的“0”。

实际上，在一个万组内，末尾所有连续的“0”都不用读，如500：五百、20：二十。这方面刚好上面的代码就是这样处理的。注意这个规则不仅仅针对数字最末尾的“0”，而是对每一个万组都有效的。比如2005678：二百万五千六百七十八（不加“零”）。

在一个万组内，如果两个非零数字之间有一个或者多个“0”，都需要（且只需要）读一个“零”。如201：二百零一、3006：三千零六、1020：一千零二十。

一个万组内，如果高位数字是0，那么是否需要读出来就看更高的万组是什么情况了。如果没有更高的万组，就不用读，否则就需要。比如0200（实际上首位的0就不出现了）：二百、10200：一万零二百。

添加两个局部变量来记录一下状态，一个是“group_is_zero”记录当前处理的万组是否仍然是全0，另一个是“need_zero”记录是否需要添加一个“零”。



全零的万组
接下来遇到的问题是，如果一个万组完全是0，就不要再添加对应的单位了，比如100000000：一亿（现在会输出“一亿万”）。

解决方法很简单，把上面的if unit == 0:改成if unit == 0 and not group_is_zero:即可。完整代码略。

麻烦的“1”
最后一种特殊的情况是由数字“1”引起的。

在一个万组内，如果千位和百位都是“0”，十位是“1”，那么这个“一”就不用读出来，比如10：十、14：十四。

但如果千位或者百位不是“0”，这个“一”就需要读出来，比如213：二百一十三、2013：二千零一十三。

当更高的万组存在时，即使当前万组的千位和百位都为“0”，也需要读出“一”，比如20010：二万零一十。

解决的方法是在上面的words.append(CHINESE_DIGITS[digit])前面增加条件：

if digit != 1 or unit != 1 or not group_is_zero or (group == 0 and need_zero):


def _enumerate_digits(number):
"""
:type number: int|long
:rtype: collections.Iterable[int, int]
"""
position = 0
while number > 0:
    digit = number % 10
    number //= 10
    yield position, digit
    position += 1



# Begin core loop.
# Version 0.4
group_is_zero = True
need_zero = False
for position, digit in reversed(list(_enumerate_digits(number))):
    unit = position % len(CHINESE_UNITS)
    group = position // len(CHINESE_UNITS)

    if digit != 0:
        if need_zero:
            words.append(CHINESE_ZERO)

        if digit != 1 or unit != 1 or not group_is_zero or (group == 0 and need_zero):
            words.append(CHINESE_DIGITS[digit])

        words.append(CHINESE_UNITS[unit])

    group_is_zero = group_is_zero and digit == 0

    if unit == 0 and not group_is_zero:
        words.append(CHINESE_GROUP_UNITS[group])

    need_zero = (digit == 0 and (unit != 0 or group_is_zero))

    if unit == 0:
        group_is_zero = True

# End core loop.