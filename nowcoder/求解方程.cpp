#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int x=0,n=0,xr=0,nr=0; int flag =0;
void Adds(string a,char op)
{
   if(flag==0)  // 等式左边
   {
        if(a[a.size()-1]=='x') //  处理的该项为x的系数
        {
            if(a=="x")
                 x += (op=='+'?1:-1);
            else
            {
                a.erase(a.size()-1,a.size()); int temp = stoi(a);
                x +=(op=='+'?temp:-temp);
            }
        }
        else   //处理的为常数项
        {
            int temp = stoi(a);
            n +=(op=='+'?temp:-temp);
        }
   }
   else  // 处理的为等式右边
   {
       if(a[a.size()-1]=='x') //
        {
            if(a=="x")
                 xr += (op=='+'?1:-1);
            else
            {
                a.erase(a.size()-1,a.size()); int temp = stoi(a);
                xr +=(op=='+'?temp:-temp);
            }
        }
        else
        {
            int temp = stoi(a);
            nr +=(op=='+'?temp:-temp);
        }
   }
}

int main()
{
    string str;getline(cin,str);int i=0;
     char c = '+';if(str[0]=='-') {c='-'; i++;} // 判断第一项的正负号//若第一项为-x;i++
    for(;i<str.size();i++)
    {
        string temp;
        while(i<str.size() && str[i]!='-' && str[i]!='+' && str[i]!='=')  // 获取每一项
           {
               temp +=str[i];i++;
           }
        Adds(temp,c);
        if(str[i]=='=')    //  处理等式右边置flag1，并且判断等式右边第一项的正负号
        {      flag =1;
                if(str[i+1]=='-')  {c='-';i++;}//若等式后第一项为-x;i++
                else c='+';
        }
        else c=str[i];  //改变符号
    }
    x = x-xr;nr = nr-n;

    if(x==0 && nr!=0) // 无解
        printf("-1");
    else if(x==0 && nr==0)//无穷多解
        printf("-1");
    else  //  假设解都为正整数
        printf("%d",nr/x);
   // printf("%d %d %d %d",x,n,xr,nr);
}



#include <bits/stdc++.h>

using namespace std;
string str, str_l, str_r;

struct node
{
    // a表示x前面的系数，b表示常数系数
    double a, b;
};

// 判断优先级的大小
int priority(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void calc(stack <char> &op, stack <node> &num)
{
    node bb = num.top();
    num.pop();
    node aa = num.top();
    num.pop();
    node temp_node;

    switch (op.top())
    {
    case '+':
        temp_node.a = aa.a + bb.a;
        temp_node.b = aa.b + bb.b;
        num.push(temp_node);
        break;
    case '-':
        temp_node.a = aa.a - bb.a;
        temp_node.b = aa.b - bb.b;
        num.push(temp_node);
        break;
    case '*':
        // 处理一元一次方程，不考虑二次项
        temp_node.a = aa.a * bb.b + aa.b * bb.a;
        temp_node.b = aa.b * bb.b;
        num.push(temp_node);
        break;
    case '/':
        temp_node.a = aa.a / bb.b;
        temp_node.b = aa.b / bb.b;
        num.push(temp_node);
        break;
    }
    op.pop();
}

int main()
{
    while (1)
    {
        cin >>str;

        // 得到str_l, str_r
        for (int i = 0; i < str.size(); ++ i)
        {
            if (str[i] == '=')
            {
                str_l = str.substr(0, i);
                str_r = str.substr(i + 1, str.size());
            }
        }

        // 定义符号栈、数字栈
        stack <node> num_l;
        stack <node> num_r;
        stack <char> op_l;
        stack <char> op_r;
        // 定义左右两边串的长度
        int len_l = str_l.size();
        int len_r = str_r.size();

        // 遍历左边的字符串
        for (int i = 0; i < len_l; ++ i)
        {
            if (isdigit(str_l[i]))
            {
                node temp_node;
                double temp = atof(&str_l[i]);
                while (isdigit(str_l[i]) || str_l[i] == '.')
                    ++ i;
                if (str_l[i] == 'x')
                {
                    temp_node.a = temp;
                    temp_node.b = 0;
                    num_l.push(temp_node);
                }
                else
                {
                    temp_node.a = 0;
                    temp_node.b = temp;
                    num_l.push(temp_node);
                    -- i;
                }
            }
            else if (str_l[i] == 'x')
            {
                node temp_node;
                temp_node.a = 1;
                temp_node.b = 0;
                num_l.push(temp_node);
            }
            else if (str_l[i] == '(')
            {
                op_l.push(str_l[i]);
            }
            else if (str_l[i] == ')')
            {
                while (op_l.top() != '(')
                    calc(op_l, num_l);
                op_l.pop();
            }
            else if (op_l.empty())
            {
                op_l.push(str_l[i]);
            }
            else if (priority(op_l.top()) < priority(str_l[i]))
            {
                op_l.push(str_l[i]);
            }
            else if (priority(op_l.top()) >= priority(str_l[i]))
            {
                while (!op_l.empty() && priority(op_l.top()) >= priority(str_l[i]))
                    calc(op_l, num_l);
                op_l.push(str_l[i]);
            }
        }

        // 遍历右边的字符串
        for (int i = 0; i < len_r; ++ i)
        {
            if (isdigit(str_r[i]))
            {
                node temp_node;
                double temp = atof(&str_r[i]);
                while (isdigit(str_r[i]) || str_r[i] == '.')
                    ++ i;
                if (str_r[i] == 'x')
                {
                    temp_node.a = temp;
                    temp_node.b = 0;
                    num_r.push(temp_node);
                }
                else
                {
                    temp_node.a = 0;
                    temp_node.b = temp;
                    num_r.push(temp_node);
                    -- i;
                }
            }
            else if (str_r[i] == 'x')
            {
                node temp_node;
                temp_node.a = 1;
                temp_node.b = 0;
                num_r.push(temp_node);
            }
            else if (str_r[i] == '(')
            {
                op_r.push(str_r[i]);
            }
            else if (str_r[i] == ')')
            {
                while (op_r.top() != '(')
                    calc(op_r, num_r);
                op_r.pop();
            }
            else if (op_r.empty())
            {
                op_r.push(str_r[i]);
            }
            else if (priority(op_r.top()) < priority(str_r[i]))
            {
                op_r.push(str_r[i]);
            }
            else if (priority(op_r.top()) >= priority(str_r[i]))
            {
                while (!op_r.empty() && priority(op_r.top()) >= priority(str_r[i]))
                    calc(op_r, num_r);
                op_r.push(str_r[i]);
            }
        }


        while (!op_l.empty())
            calc(op_l, num_l);
        while (!op_r.empty())
            calc(op_r, num_r);

        double x1 = num_l.top().a, y1 = num_l.top().b;
        double x2 = num_r.top().a, y2 = num_r.top().b;

        // cout <<x1 <<" " <<y1 <<" " <<x2 <<" " <<y2 <<endl;
        if(x1 - x2 == 0.0) 
            cout << "-1";
        else
        printf("%.2lf\n", (y2 - y1) / (x1 - x2));
    }


    return 0;
}