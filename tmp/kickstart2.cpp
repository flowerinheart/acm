// circuit board has R rows and C columns of squares.
// Each square of the circuit board has a thickness, measured in millimetres   v(r,c)
// 好的电路板，每一行，最后最博的差不大于K


#include <bits/stdc++.h>
using namespace std;
int V[301][301];
int dp[301][301];


// Each test case begins with one line containing three integers R, C and K
//  there are R more lines containing C integers each
   int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[st.top()] < height[i]) {
                st.push(i);
            } else {
                int cur = st.top(); st.pop();
                res = max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }     
        }
        return res;
    };
    // for(int j = 0;j < R;j++){
    //         dp[j][0] = 1;
    //         for(int k = 1;k < C;k++){
    //             if(abs(V[j][k] - V[j][k-1]) <= K){
    //                 dp[j][k] = dp[j][k-1] + 1;
    //             } else {
    //                 dp[j][k] = 1;
    //             }
    //         }
    //     }
int main() {
    int T, R, C, K;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> R >> C >> K;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                cin >> V[i][j];
        for(int i = 0;i < R;i++){
            for(int j = 0;j < C;j++){
                if(j == 0) 
                    dp[i][j] = 1;
                else {
                    int k = j - 1;
                    for(; k >= j - dp[i][j - 1];k--) 
                        if(k < 0 || abs(V[i][k] - V[i][j]) > K)
                            break;
                    dp[i][j] = j - k;
                }
            }
        }
            int maxArea = 0;
        for(int j = 0; j < C; j++) {
            vector<int> heights;
            for(int k = 0; k < R; k++)
                heights.push_back(dp[k][j]);
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        printf("Case #%d: %s", t, to_string(maxArea).c_str());
    }
}
