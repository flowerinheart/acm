#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
int main(){
    string s;
    int i,j,num,len;
    while(cin>>s){
        int len = str.size();
        for (int x = 5; x < len; x++) { // x为截取宝石的个数
            for (int y = 0; y < len; y++) {//y为x确定的情况下迭代的次数
                string temp;
                for (int z = y; z < y + x; z++) {
                    temp.push_back(str[z % len]);
                }
                if (str.contains("A") && t.contains("B") && t.contains("C") && t.contains("D") && t.contains("E")) {
                    return len - x;
                }
            }
        }
        return 0;
        len=s.length();
        s=s+s;
        i=0,j=0,num=0;
        int Min=len;
        map<char,int> book;
        while(true){
            while(i<s.length()&&num<5){
                if(s[i] >= 'A' && s[i] <= 'E' && book[s[i]]++==0)
                    num++;
                i++;
            }
            if(num<5) break;
            Min=min(Min,i-j);
            cout << Min << " ";
            if(s[j] >= 'A' && s[j] <= 'E' &&--book[s[j]]==0)
                num--;
            j++;
        }
        printf("%d\n",len-Min);
    }
}
