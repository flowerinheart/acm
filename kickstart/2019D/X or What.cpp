#include <bits/stdc++.h>
using namespace std;
int nums[100001];
int sums[100001];



bool isEven(int v){
    int count = 0; 
    while(v != 0)
    {
        if((v & 1) == 1)
            count++;
        v = v >> 1;
    }
    return count % 2 == 0;
}

//If there are no xor-even subintervals, then output 0.
int findMax(int n){
    int maxLen = 0;//这里千万不能用-1
    for(int b = 0; b < n; b++) {
        for(int e = n - 1; e >= b; e--) {
            int temp = (b == 0 ? sums[e] : sums[e] ^ sums[b - 1]);
            if(isEven(temp)) {
                maxLen = max(maxLen, e - b + 1);
                break;
            }
        }
    }
    return maxLen;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    cin >> T;
    int n, q;
    int p, v;
    for(int t = 0; t < T; t++)
    {
        cin >> n >> q;
        for(int i = 0; i < n; i++) 
        {
            cin >> nums[i];
            if(i == 0)
                sums[0] = nums[0];
            else
                sums[i] = sums[i - 1] ^ nums[i];
        }
        cout << "Case #" << t + 1 << ": ";//4 3 4
        for(int i = 0; i < q; i++) {
            cin >> p >> v;
            for(int j = p; j < n; j++)
                sums[j] = sums[j] ^ nums[p] ^ v;
            nums[p] = v;
            cout << findMax(n);
            if(i == q - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
        
}