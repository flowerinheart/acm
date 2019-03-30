/*
作者:Darnell
题目:p1201 最小数和最大数
*/

/*
//如何写一份可以提交的代码？以P1000 A+B为例
#include <iostream>
using namespace std;
int main()
{
    int a, b; //定义两个变量名
    cin >> a >> b; //从标准输入流中输入两个整数
    cout << a + b << endl; //输出到标准输出流中

}
// 完成程序以后，点击下方的提交，即可看到测试结果
*/

#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
pair<int, int> getpos(int c) {
    if(c == 0)
        return make_pair(3, 1);
    else
        return make_pair((c - 1) / 3, (c - 1) % 3);
}
int output;
bool backtrace(string &str, pair<int, int> pos, int j, bool full, int res) {
    if(j == str.size()) {
        output = res;
        return true;
    }
    int c = full ? str[j] - '0' : 9;
    for(int k = c; k >= 0; k--) {
        pair<int, int> tpos = getpos(k);
        if(pos.first <= tpos.first && pos.second <= tpos.second) {
            cout << res << " " << c << " " << pos.first << "," << pos.second <<  " " << tpos.first << "," << tpos.second << endl;
            if(full && k < c)
                full = false;
            if(backtrace(str, tpos, j + 1, full, res * 10 + k))
                return true;
        }
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        backtrace(str, make_pair(0, 0), 0, true, 0);
        cout << output << "\n";
    }
}
