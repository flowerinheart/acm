#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

vector<int> posiBuffer(256, -1);
int longestSubstring(string & str) {
    int strSize = str.size();
    if(strSize <= 1) return strSize;
    for(int i = 0; i < 256; i++)
        posiBuffer[i] = -1;
    int resu = 1;
    int dp = 1;
    posiBuffer[str[0]] = 0;
    for(int i = 1; i < strSize; i++) {
        char c = str[i];
        int dis = i - posiBuffer[c];
        if(dis > dp) 
            dp = dp + 1;
        else 
            dp = dis;
        resu = max(resu, dp);
        posiBuffer[c] = i;
    }
    return resu;
}


int main() {
    string str;
    cin >> str;
    cout << longestSubstring(str);
}